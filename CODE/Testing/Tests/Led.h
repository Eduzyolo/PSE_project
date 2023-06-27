#include <Adafruit_NeoPixel.h>

// Define the pin connected to the LED strip
const int LED_PIN = 18;

// Define the number of LEDs in the strip
const int NUM_LEDS = 8;

// Initialize the LED strip object with the specified number of LEDs and pin
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
