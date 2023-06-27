#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// Initialize the LED strip object with the specified number of LEDs and pin
Adafruit_NeoPixel strip(STRIP_LENGHT, LED_STRIP, NEO_GRB + NEO_KHZ800);

void setup_led();
void loop_led();
uint32_t Wheel(byte WheelPos);


void setup_led() {
    // Initialize the LED strip
    strip.begin();
    strip.show();
}

void loop_led() {
    // Set all LEDs to the same color
    for (int c = 0; c < 256; c++) {
        for (int i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel(c));
        }
        strip.show();
        delay(10);
    }
}

uint32_t Wheel(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85) {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else if (WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    } else {
        WheelPos -= 170;
        return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
}