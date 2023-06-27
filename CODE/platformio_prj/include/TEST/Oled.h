#ifdef TEST_OLED


#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Initialize the OLED display object with the specified width and height
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Define the figures to be displayed
const uint8_t figures[5][8] = {
    { 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00 },  // Square
    { 0x08, 0x1C, 0x2A, 0x08, 0x08, 0x08, 0x08, 0x00 },  // Arrow
    { 0x18, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00 },  // House
    { 0x1C, 0x22, 0x04, 0x08, 0x10, 0x22, 0x1C, 0x00 },  // Smiley face
    { 0x1C, 0x22, 0x22, 0x1C, 0x08, 0x14, 0x22, 0x00 }   // Diamond
};

// Define the current figure index
int currentFigure = 0;

void setup_oled() {
    // Initialize serial communication
    Serial.begin(SERIAL_BAUD_RATE);
    
    // Start the I2C bus
    Wire.begin();

    // Initialize the OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }

    // Clear the screen and display the first figure
    display.clearDisplay();
    display.drawBitmap(0, 0, figures[currentFigure], 8, 8, WHITE);
    display.display();
}

void loop_oled() {
    // Wait for one second
    delay(1000);

    // Increment the current figure index and wrap around if necessary
    currentFigure++;
    if (currentFigure >= 5) {
        currentFigure = 0;
    }

    // Clear the screen and display the next figure
    display.clearDisplay();
    display.drawBitmap(0, 0, figures[currentFigure], 8, 8, WHITE);
    display.display();
}
#endif