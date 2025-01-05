Here's an example code for using a relay module with WiFi control using an ESP8266 (or ESP32) board. This code will allow you to control a relay via a web interface over WiFi.

Requirements:
Hardware: ESP8266 or ESP32, relay module, and a device (phone, computer) to control the relay via a web browser.
Software: Arduino IDE, with ESP8266/ESP32 board package installed.
Circuit Diagram:
Relay module: Connect the IN pin of the relay to a GPIO pin (e.g., D1 or GPIO5).
ESP8266 or ESP32: Make sure the relay module's VCC and GND are properly connected to the board.

Explanation:
WiFi Setup: The code connects the ESP8266 to your WiFi using the provided ssid and password.
Web Server: The ESP8266WebServer library is used to set up a basic web server. It listens for HTTP GET requests and controls the relay accordingly.
Relay Control: The relay is controlled by sending a HIGH signal to the GPIO pin connected to the relay for "ON" and a LOW signal for "OFF".
Web Interface: The web page served by the ESP8266 allows you to turn the relay on or off using simple links.
Steps to upload the code:
Open the Arduino IDE and make sure you have the correct board selected (ESP8266 or ESP32).
Connect your ESP8266 or ESP32 to your computer.
Install the ESP8266 or ESP32 board package in the Arduino IDE if you haven't done so already.
Select the correct COM port and upload the code.
Open the Serial Monitor, and after the ESP connects to WiFi, note the IP address displayed.
Open a web browser and navigate to that IP address (e.g., http://192.168.1.x).
You should see the web page where you can turn the relay on and off.
Notes:
Ensure the relay module is powered properly.
You can customize the GPIO pin used for the relay control (e.g., D1, D2, etc.) depending on your wiring.

Created by https://ecmd.ro 
