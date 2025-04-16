#define BLYNK_TEMPLATE_ID "TMPL3lXbVhKeU"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "z-4HUcHlIHepljpeCB4TjSU0K3jcZFmS"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "IC_IITP";
char pass[] = "iciitp@9911";

// Relay control pins
#define RELAY1_PIN  4    // D4 - IN1 (Bulb 1)
#define RELAY2_PIN  18   // D18 - IN3 (Bulb 2)

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Turn OFF both relays initially
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
}

// V0 controls Bulb 1
BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(RELAY1_PIN, value);
  Serial.print("Bulb 1: "); Serial.println(value);
}

// V1 controls Bulb 2
BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(RELAY2_PIN, value);
  Serial.print("Bulb 2: "); Serial.println(value);
}

void loop() {
  Blynk.run();
}




