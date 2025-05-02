#include <Arduino.h>

#define LED_PIN 26
#define BUTTON_PIN 4

// Button debounce variables
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50; // milliseconds

// LED state
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // digitalWrite(LED_PIN, LOW);
  Serial.begin(115200);
  Serial.println("System ready - Only LED control active");
}

void loop() {
  int currentButtonState = !digitalRead(BUTTON_PIN);
  // Button debounce logic
  if (millis() - lastDebounceTime > debounceDelay) {
    if (currentButtonState ==HIGH ) {
      digitalWrite(LED_PIN, HIGH);
      lastDebounceTime = millis();

      
    } else {
      digitalWrite(LED_PIN, LOW);
      lastDebounceTime = millis();

    }
    
  }
  
}