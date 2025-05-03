#include <Arduino.h>
#include <AccelStepper.h>

// Pin definitions
#define X_STEP_PIN 2
#define X_DIR_PIN 4
#define Y_STEP_PIN 16
#define Y_DIR_PIN 17
#define Z_STEP_PIN 18
#define Z_DIR_PIN 19
#define LED_PIN 5

#define ENDSTOP_X_PIN 32
#define ENDSTOP_Y_PIN 33
#define ENDSTOP_Z_PIN 25

// Motor objects
AccelStepper stepperX(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);

//déclaration des fonctions
void initializeHardware();

// Button debounce variables
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50; // milliseconds

// LED state
bool ledState = false;

void setup() {
  
  Serial.begin(115200);
  initializeHardware();
  
}

void loop() {

  Serial.println("Moving to position 1000");
  stepperX.moveTo(1000);
  
  while(stepperX.distanceToGo()!=0){
    stepperX.run();
  }
  
   delay(500);
   Serial.println("Moving to position 400");
  stepperX.moveTo(400);
  
  while(stepperX.distanceToGo()!=0){
    stepperX.run();
  }
  delay(500);

  
  

}

void initializeHardware() {
  // Configure motor
  stepperX.setMaxSpeed(1000);
  stepperX.setAcceleration(500);
  
  // Configure endstops
  pinMode(ENDSTOP_X_PIN, INPUT_PULLUP);
  pinMode(ENDSTOP_Y_PIN, INPUT_PULLUP);
  pinMode(ENDSTOP_Z_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}