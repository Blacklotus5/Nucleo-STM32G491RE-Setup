#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type (Most cheap modules are FC16_HW)
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4 // Set this to the number of 8x8 segments you have

// Define Pins
#define CLK_PIN   PA5  // D13
#define DATA_PIN  PA7  // D11
#define CS_PIN    PB6  // D10

// Create the display object
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  myDisplay.begin();           // Initialize the display
  myDisplay.setIntensity(5);    // Set brightness (0-15)
  myDisplay.displayClear();     // Clear the matrix
  
  // Set the text, alignment, speed, and effect
  // Arguments: Text, Alignment, Speed, Pause Time, Effect In, Effect Out
  myDisplay.displayText("HELLO STM32", PA_CENTER, 100, 2000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void loop() {
  // Check if the animation is finished and restart it
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}