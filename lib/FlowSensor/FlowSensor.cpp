#include <Arduino.h>
#include "../../src/Configuration.h"
#include "FlowSensor.h"

volatile int FlowSensor::count = 0; // This integer needs to be volatile to be accessible by the ISR

void IRAM_ATTR FlowSensor::ISR()
{
  FlowSensor::count++; // Every time this function is called, increment "count" by 1
}

void FlowSensor::init()
{
  pinMode(FLOW_SENSOR_PIN, INPUT);                            // Sets the pin as an input
  attachInterrupt(FLOW_SENSOR_PIN, &FlowSensor::ISR, RISING); // Attaches interrupt to track the pulses
}

float FlowSensor::read()
{
  // Disable the interrupt while calculating flow rate
  detachInterrupt(FLOW_SENSOR_PIN);

  // Calculate the flow rate
  flowRate = ((1000.0 / (millis() - lastUpdateTime)) * count) / FLOW_SENSOR_CALIBRATION_FACTOR;

  // Reset the pulse counter so we can start incrementing again
  count = 0;

  // Store the time the flow rate was last read
  lastUpdateTime = millis();

  // Enable the interrupt again
  attachInterrupt(FLOW_SENSOR_PIN, &FlowSensor::ISR, RISING);

  return flowRate;
}