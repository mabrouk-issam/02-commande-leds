#include <Arduino.h>

#define LED1_PIN 5
#define BUTTON1_PIN 32

void commanderLed(int led, int button);


// Button debounce variables
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50; // milliseconds

// LED state
bool ledState = false;

void setup() {
  pinMode(LED1_PIN, OUTPUT);

  pinMode(BUTTON1_PIN, INPUT_PULLUP);

  // digitalWrite(LED_PIN, LOW);
  Serial.begin(115200);
  Serial.println("System ready - Only LED control active");
}

void loop() {
 commanderLed(LED1_PIN,BUTTON1_PIN);

}

void commanderLed(int led, int button){
  int currentButtonState = !digitalRead(button);
  // Button debounce logic
  if (millis() - lastDebounceTime > debounceDelay) {
    if (currentButtonState ==HIGH ) {
      digitalWrite(led, HIGH);
      lastDebounceTime = millis();

      
    } else {
      digitalWrite(led, LOW);
      lastDebounceTime = millis();

    }
    
  }
}