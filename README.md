# ESP8266-Virtual-Buttons
Use [Virtual Buttons](https://amzn.to/3fNU09R) to trigger an Alexa Routine with an ESP8266

## What is Virtual Buttons?
Virtual Buttons combines an Alexa Smart Home skill with a REST API, allowing you to trigger Alex Routines with a simple REST call. To learn more about Virtual Buttons, please visit www.virtualbuttons.com

## Caveats
This ESP8266 example sketch uses insecure mode to contact Virtual Buttons' HTTPS endpoint. In general, using insecure mode is considered a "bad" thing. But, it is our opinion that the only thing you are risking is having someone discover your access code (that is the only "personal" data you should be passing to the API), and that is an _extremely_ low risk. _If_ you think someone has acquired your Virtual Buttons access code and is using it to annoyingly pushing your buttons, just disable/re-enable the skill to change your access code to something else.

## How to Use It
Use of our example sketch assumes you have an Alexa device and an [ESP8266 device setup for use with the Arduino IDE](https://randomnerdtutorials.com/installing-esp8266-nodemcu-arduino-ide-2-0/). With these things in place, your next steps are:
1. Follow the instructions on www.virtualbuttons.com to enable the Virtual Buttons skill and ensure it is working for you
1. Download the [ESP8266_Virtual_Buttons.ino file](https://github.com/Thomptronics/ESP8266-Virtual-Buttons/blob/master/ESP8266_Virtual_Buttons.ino) and open it with the Arduino IDE
1. Change the WIFISSID, WIFIPASS, and VBACCESSCODE defines in the ESP8266_Virtual_Buttons.ino file to match your SSID, WiFi password, and Virtual Buttons access code
1. Upload the edited sketch to your ESP8266 and see if it works
1. Think up all the great things you can now do with your ESP8266 and Alexa!
