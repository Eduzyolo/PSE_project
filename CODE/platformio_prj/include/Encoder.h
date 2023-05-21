#include <Wire.h>
#include <AS5600.h>

AS5600 as5600;                // AS5600 object
int rotationCountCW = 0;      // Counter for clockwise rotations
int rotationCountCCW = 0;     // Counter for counterclockwise rotations
int previousAngle = 0;        // Previous angle reading from the encoder

void setup_encoder() {
  Wire.begin();               // Initialize I2C communication
  Serial.begin(SERIAL_BAUD_RATE);
  
  as5600.begin();             // Initialize the AS5600 encoder
  as5600.setMode(AS5600_MODE_CONTINUOUS);
}

void loop_encoder() {
  int currentAngle = as5600.getPosition();  // Read the current angle from the encoder

  // Check for clockwise rotation
  if (currentAngle < previousAngle) {
    if (previousAngle - currentAngle > 180) {
      rotationCountCW++;
    }
  }

  // Check for counterclockwise rotation
  if (currentAngle > previousAngle) {
    if (currentAngle - previousAngle > 180) {
      rotationCountCCW++;
    }
  }

  previousAngle = currentAngle;  // Update the previous angle

  // Print the rotation counts
  Serial.print("CW rotations: ");
  Serial.print(rotationCountCW);
  Serial.print(", CCW rotations: ");
  Serial.println(rotationCountCCW);

  delay(100);   // Delay for stability
}
