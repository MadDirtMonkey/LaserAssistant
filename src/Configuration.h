// I2C config
#define SCL_PIN 19
#define SDA_PIN 23

// Screen config
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // Screens I2C address

// Thermistor config
#define THERMISTOR_POWER_PIN 17 // Pin that provides power when HIGH
#define THERMISTOR_PIN 34       // Analog pin connected to the thermistor