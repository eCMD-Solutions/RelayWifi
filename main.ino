#include <ESP8266WiFi.h>  // For ESP8266, use ESP32WiFi.h for ESP32
#include <ESP8266WebServer.h>  // Web server for ESP8266, use ESP32WebServer.h for ESP32

// Replace with your network credentials
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

// Define the GPIO pin connected to the relay
const int relayPin = D1;  // Change to the appropriate GPIO pin

// Create a web server on port 80
ESP8266WebServer server(80);

// Function to handle relay on
void relayOn() {
  digitalWrite(relayPin, HIGH);  // Turn the relay ON
  server.send(200, "text/html", "<html><body><h1>Relay is ON</h1><a href='/off'>Turn OFF</a></body></html>");
}

// Function to handle relay off
void relayOff() {
  digitalWrite(relayPin, LOW);  // Turn the relay OFF
  server.send(200, "text/html", "<html><body><h1>Relay is OFF</h1><a href='/on'>Turn ON</a></body></html>");
}

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  // Print the local IP address
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize the relay pin
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Make sure the relay is initially OFF

  // Define HTTP routes
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", "<html><body><h1>Relay Control</h1><a href='/on'>Turn ON</a><br><a href='/off'>Turn OFF</a></body></html>");
  });

  server.on("/on", HTTP_GET, relayOn);
  server.on("/off", HTTP_GET, relayOff);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle client requests
  server.handleClient();
}
