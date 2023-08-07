// ==============================
// General Configuration
// ==============================

// Safety thresholds
#define MAX_SAFE_TEMPERATURE 24 // Maximum safe temperature of the coolant (in degrees Celsius)
#define MIN_SAFE_TEMPERATURE 16 // Minimum safe temperature of the coolant (in degrees Celsius)
#define MIN_SAFE_FLOW 10        // Minimum safe flow rate of the coolant (in litres per minute)

// Other
#define POLLING_RATE 1000 // Polling rate for readings and screen updates in milliseconds

// ==============================
// Hardware configuration
// ==============================

// I2C configuration
#define SCL_PIN 19 // The pin number for the I2C SCL (clock) line
#define SDA_PIN 23 // The pin number for the I2C SDA (data) line

// Screen configuration
#define SCREEN_WIDTH 128    // The width of the OLED display in pixels
#define SCREEN_HEIGHT 64    // The height of the OLED display in pixels
#define SCREEN_RESET_PIN -1 // The pin number for the screen reset (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // The I2C address of the screen

// Thermistor configuration
#define THERMISTOR_BETA_VALUE 3950        // The Beta value of the thermistor (should be provided in the datasheet, can be calculated if unknown)
#define THERMISTOR_POWER_PIN 17           // The pin number that provides power to the thermistor when set to HIGH
#define THERMISTOR_PIN 34                 // The analog pin connected to the thermistor
#define THERMISTOR_NOMINAL_TEMPERATURE 25 // The nominal temperature of the thermistor (in degrees Celcius)
#define THERMISTOR_NOMINAL_RESISTANCE 10  // The nominal resistance of the thermistor (in K ohms)

// Buzzer configuration
#define BUZZER_PIN 16 // The pin number for the buzzer

// Flow sensor configuration
#define FLOW_SENSOR_PIN 18                 // The pin number for the flow sensor
#define FLOW_SENSOR_CALIBRATION_FACTOR 7.5 // The number of pulses per L/min