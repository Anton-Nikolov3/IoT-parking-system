#include <WiFi.h>
#include "wifi_config.h"
#include "sensors.h"

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected!");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  float distance = readDistance();
  String status = (distance < 10) ? "occupied" : "free";

  WiFiClient client = server.available();
  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println();

    client.print("{\"status\": \"");
    client.print(status);
    client.print("\"}");

    client.stop();
  }

  delay(1000);
}
