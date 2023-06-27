#ifndef MAGNETIC_ENCODER_H
#define MAGNETIC_ENCODER_H

// Macros for setup values
#define DIAMETER 10.0
#define ENC_RESOLUTION 1000

// Macro to calculate the distance
#define CALCULATE_DISTANCE(currentPosition) \
  ((((float)currentPosition / ENC_RESOLUTION) * (PI * DIAMETER)) * 2.54)

#endif // MAGNETIC_ENCODER_H
