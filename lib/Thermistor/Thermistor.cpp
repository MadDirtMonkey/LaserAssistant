#include "Thermistor.h"
#include "../../src/Configuration.h"

#include <esp_adc_cal.h>
#include <RunningMedian.h>

#define R1 10000          // Other resistors value in the divider
#define SAMPLE_COUNT 255  // Count for signal averaging
#define DEFAULT_VREF 1100 // mV

esp_adc_cal_characteristics_t adc1_chars;
RunningMedian samples = RunningMedian(SAMPLE_COUNT);
uint32_t Vo;
float logR2, R2, T, Tc;

void Thermistor::init()
{
  analogSetWidth(11);       // set the resolution width to be 2048 instead of the default 4096 to try and reduce noise
  analogReadResolution(11); // set the resolution to be 2048 instead of the default 4096 to try and reduce noise"
  pinMode(THERMISTOR_POWER_PIN, OUTPUT);
  pinMode(34, INPUT);

  adc_power_acquire();
  adc1_config_width(ADC_WIDTH_BIT_11);
  adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11);
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_11, ESP_ADC_CAL_VAL_DEFAULT_VREF, &adc1_chars);
}

float Thermistor::read()
{
  // Power up
  digitalWrite(THERMISTOR_POWER_PIN, HIGH);
  delay(100); // Sleep a bit to let things stabilize

  // Take X (corrected) readings for some noise correction
  for (byte i = 0; i < SAMPLE_COUNT; i++)
  {
    esp_adc_cal_get_voltage(ADC_CHANNEL_6, &adc1_chars, &Vo);
    samples.add(Vo);
  }

  // Power down
  digitalWrite(THERMISTOR_POWER_PIN, LOW);

  // Get the average of the 50th percentile of the samples
  float voltage = samples.getAverage(SAMPLE_COUNT / 2);

  // Calculate the resistance of the thermistor
  float resistance = THERMISTOR_NOMINAL_RESISTANCE * (3300 / voltage - 1.0);

  // Serial.printf("Calculated thermistor resistance: %f\n", resistance);

  // Calculate the temperature using the Beta formula
  float temperature = (1.0 / ((log(resistance / THERMISTOR_NOMINAL_RESISTANCE) / THERMISTOR_BETA_VALUE) + (1.0 / (THERMISTOR_NOMINAL_TEMPERATURE + 273.15)))) - 273.15;

  return temperature;
}
