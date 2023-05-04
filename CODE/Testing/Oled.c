#include "Oled.h" 

void setup_oled() {
    // Initialize serial communication
    Serial.begin(9600);
    
    // Start the I2C bus
    Wire.begin();

    // Initialize the OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
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
