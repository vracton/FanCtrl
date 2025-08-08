#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "Your_Blynk_Auth_Token";

char ssid[] = "Your_SSID";
char pass[] = "Your_Password";

int solenoid1Pin = 1;
int solenoid2Pin = 10;

bool light_state = false;
bool fan_state = false;

void setup() {
  Serial.begin(115200);
  pinMode(solenoid1Pin, OUTPUT);
  pinMode(solenoid2Pin, OUTPUT);
  
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
    delay(100);
    digitalWrite(solenoid1Pin, LOW);
    
    light_state = !light_state;
    if (light_state) {
      Serial.println("light on");
    } else {
      Serial.println("light off");
    }
  }
}

BLYNK_WRITE(V2) {
  int pinValue = param.asInt();
  
  if (pinValue == 1) {
    digitalWrite(solenoid2Pin, HIGH);
    delay(100);
    digitalWrite(solenoid2Pin, LOW);
    
    fan_state = !fan_state;
    if (fan_state) {
      Serial.println("fan on");
    } else {
      Serial.println("fan off");
    }
  }
}
