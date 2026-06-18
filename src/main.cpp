#include <Arduino.h>
bool debug = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(23, INPUT_PULLDOWN);
  if (digitalRead(23) == HIGH) {
    Serial.begin(115200);
    Serial.println("modo debug");
    debug = true;
  };
};

void loop() {
  if (debug == true) {
    vTaskDelay(pdMS_TO_TICKS(1000));
    digitalWrite(2, HIGH);
    vTaskDelay(pdMS_TO_TICKS(1000));
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, LOW);
  };
};
