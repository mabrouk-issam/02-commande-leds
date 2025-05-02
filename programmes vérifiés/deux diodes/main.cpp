#include <Arduino.h>

//déclaration des constantes
#define LED1_PIN 27
#define LED2_PIN 26
#define BUTTON1_PIN 2
#define BUTTON2_PIN 4

//déclaration des fonctions
void commanderLed(int led, int button);


// Button debounce variables
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50; // milliseconds

// LED state
bool ledState = false;

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);

  // digitalWrite(LED_PIN, LOW);
  Serial.begin(115200);
  Serial.println("System ready - Only LED control active");
}

void loop() {
 commanderLed(LED1_PIN,BUTTON1_PIN);
 commanderLed(LED2_PIN,BUTTON2_PIN);

}

//définitions des fonctions
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