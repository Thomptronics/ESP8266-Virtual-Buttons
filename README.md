# ESP8266-Virtual-Buttons
Use [Virtual Buttons](https://amzn.to/3fNU09R) to trigger an Alexa Routine with an ESP8266

## What is Virtual Buttons?
Virtual Buttons combines an Alexa Smart Home skill with a REST API, allowing you to trigger Alex Routines with a simple REST call. To learn more about Virtual Buttons, please visit www.virtualbuttons.com

The trick here is that the Virtual Buttons API requires HTTPS, which can be an issue on small devices such as the ESP8266. To learn more about HTPPS on the ESP8266, we recommend you watch [Andreas Spiess' "How to secure our devices using SSL" YouTube video](https://www.youtube.com/watch?v=Wm1xKj4bKsY)

## How it's Done
This ESP8266 sketch is based on the HTTP over TLS (HTTPS) example found [here](https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/examples/HTTPSRequestCACertAxTLS/HTTPSRequestCACertAxTLS.ino). We simply modified it a bit to include the current certificate for the api.virtualbuttons.com endpoint. _This certificate can change_, so you might have to update the certificate data in the future. That said, the certificate claims it will remain valid until June 29, 2034.

## How to Use It
Use of our example sketch assumes you have an Alexa device and an [ESP8266 device setup for use with the Arduino IDE](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/). With these things in place, your next steps are:
1. Follow the instructions on www.virtualbuttons.com to enable the Virtual Buttons skill and ensure it is working for you
1. Download the example files from this repository and open them into your Arduino IDE
1. Change the STASSID, STAPSK, and STACODE defines in the ESP8266_VB_HTTPS_call.ino file to match your SSID, WiFi password, and Virtual Buttons access code
1. Upload the edited sketch to your ESP8266 and see if it works
1. Think up all the great things you can now do with your ESP8266 and Alexa!
