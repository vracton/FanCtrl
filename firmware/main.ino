#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "Your_Blynk_Auth_Token";

char ssid[] = "Your_SSID";
char pass[] = "Your_Password";

int solenoid1Pin = 4;
int solenoid2Pin = 19;

void setup() {
  Serial.begin(115200);
  pinMode(solenoid1Pin, OUTPUT);
  pinMode(solenoid2Pin, OUTPUT);
  
  // Initialize both solenoids to OFF state
  digitalWrite(solenoid1Pin, LOW);
  digitalWrite(solenoid2Pin, LOW);
  
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  
  if (pinValue == 1) {
    digitalWrite(solenoid1Pin, HIGH); 
    Serial.println("Solenoid 1 ON");
  } else {
    digitalWrite(solenoid1Pin, LOW);
    Serial.println("Solenoid 1 OFF");
  }
}

BLYNK_WRITE(V2) {
  int pinValue = param.asInt();
  
  if (pinValue == 1) {
    digitalWrite(solenoid2Pin, HIGH);
    Serial.println("Solenoid 2 ON");
  } else {
    digitalWrite(solenoid2Pin, LOW);
    Serial.println("Solenoid 2 OFF");
  }
}