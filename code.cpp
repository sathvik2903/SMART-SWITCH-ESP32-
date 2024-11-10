#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_DEVICE_NAME "Smart Switch Board"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";

#define RELAY1 13
#define RELAY2 12
#define RELAY3 14
#define RELAY4 27

BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
}

BLYNK_WRITE(V1) {
  digitalWrite(RELAY1, param.asInt() ? LOW : HIGH);
}

BLYNK_WRITE(V2) {
  digitalWrite(RELAY2, param.asInt() ? LOW : HIGH);
}

BLYNK_WRITE(V3) {
  digitalWrite(RELAY3, param.asInt() ? LOW : HIGH);
}

BLYNK_WRITE(V4) {
  digitalWrite(RELAY4, param.asInt() ? LOW : HIGH);
}

void loop() {
  Blynk.run();
}
