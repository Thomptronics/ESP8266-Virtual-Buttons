#include <ESP8266WiFi.h>

#ifndef WIFISSID
#define WIFISSID "enter your ssid here"
#define WIFIPASS "enter your WiFi password here"
#define VBACCESSCODE "enter your access code here"  // see www.virtualbuttons.com for more information
#endif

void pressVirtualButton(int button) {
  // first let's validate the button number
  if (button>0 && button<100) {
    const char* host = "api.virtualbuttons.com";

    // next we'll attempt to reach endpoint
    BearSSL::WiFiClientSecure client;
    client.setInsecure(); // yes, this connection is insecure so don't use it to send confidential data
    if (client.connect("api.virtualbuttons.com", 443)) {

      // endpoint is good so let's call the API
      Serial.printf("\nPressing Virtual Button %d\n", button);
      client.printf("GET /v1?virtualButton=%d&accessCode=%s HTTP/1.0\r\nHost: %s\r\n\r\n", button, VBACCESSCODE, host);
      
      // wait up to five seconds for reply
      const long timout = millis()+5000;
      while (!client.available() && millis()<timout) {delay(10);}

      // then read and print the server's reply, if any
      if (client.available()) {
        Serial.println(client.readStringUntil('\n'));                     // print HTTP respsonse
        while (client.available() && client.readStringUntil('\n')!="\r"); // skip the header
        while (client.available()) {Serial.print((char)client.read());}   // and print body (if any)
        Serial.println();
      }

      // finally, we close the connection
      client.stop();

    // something went wrong if any of these else statements trigger
    } else {Serial.printf("\nERROR: Unable to connect to %s\n", host);}
  } else {Serial.printf("\nERROR: %d is not a valid button number\n", button);}
}

void setup() {
  // prep serial port
  Serial.begin(115200);
  delay(5000);  // give serial port time to setup (overkill, perhaps)

  // connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(WIFISSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFISSID, WIFIPASS);
  while (WiFi.status() != WL_CONNECTED) {delay(500);Serial.print(".");} // wait for connection
  Serial.println();
  Serial.print("WiFi connected with local IP ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // press the button
  pressVirtualButton(1);

  // pause a while between button pushes
  static int repeat = 3;
  if (--repeat > 0) {
    delay(10000);

  // "freeze" after three button pushes (otherwise this could get annoying)  
  } else {
    Serial.println();
    Serial.println("-------------------------");
    Serial.println("Done. Thanks for playing!");
    Serial.println("-------------------------");
    Serial.println();
    while (true) {delay(1000);} // wait forever!
  }
}
