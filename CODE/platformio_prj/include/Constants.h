#ifndef __DEFINES__
#define __DEFINES__

//GPIO Pin mapping   
#define LED_ALIVE 20 
#define LED_RP 25
#define LED_STRIP 13

#define SDA 0 
#define SCL 1 

#define USB_ID 2
#define USB_OUT_EN 27
#define WIFI_TX 17
#define WIFI_RX 16
#define WIFI_EN 3
#define UART_GPS_TX 4
#define UART_GPS_RX 5

#define BUTTON_UP 22
#define BUTTON_DOWN 23
#define BUTTON_RIGHT 24
#define BUTTON_LEFT 25
#define BUZZER 21

#define GPS_EN 18
#define GPS_PPS 19
#define GPS_RST 12

#define ACC_SA0 10
#define ACC_INT1 14
#define ACC_INT2 15

#define SERVO3 7
#define SERVO1 8
#define SERVO2 9

#define EN_5VOLT 11
//ANALOG INPUTS (ADC)
#define BATTERY_VOLTAGE 28
#define TEMPERAURE 26

//constants
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C //oled file to control it
#define NUM_PAGES 11 //number of pages in the oled screen tbd
#define EEPROM_ADDRESS 0x50 //hopefully, already defined in the library
#define ACC_ADDRESS 0x00
#define STRIP_LENGHT 8

// Define the I2C address of the MMA8451Q accelerometer
#define MMA8451Q_ADDR   0x1C

// Define the addresses of the MMA8451Q registers
#define MMA8451Q_CTRL_REG1      0x2A
#define MMA8451Q_OUT_X_MSB      0x01
#define MMA8451Q_OUT_Y_MSB      0x03
#define MMA8451Q_OUT_Z_MSB      0x05


enum Peripheral_state{
    MAIN_MENU,
    WIFI_SENDING,
    WIFI_RECEIVING,
    GPS_SENDING,
    ACC_SENDING,
    LEDS_DATA,
    TEMPERATURE_DATA,
    BATTERY_DATA,
    BUZZER_SIGNAL,
    PERIPHERAL_IDLE,
    PERIPHERAL_ERROR
};

#endif
