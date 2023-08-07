#include <Arduino.h>
#include <Configuration.h>
#include <Display.h>
#include <Thermistor.h>
#include <FlowSensor.h>

Display display;
Thermistor thermistor;
FlowSensor flowSensor;

unsigned long lastUpdateTime = 0;

void setup()
{
  Serial.begin(MONITOR_SPEED);
  display.init();
  thermistor.init();
  flowSensor.init();
  lastUpdateTime = millis();

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  // Check if it's time for an update
  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime > POLLING_RATE || currentTime < lastUpdateTime)
  {
    lastUpdateTime = currentTime; // Update the last update time

    float temp = thermistor.read();
    float flowRate = flowSensor.read();

    display.update(temp, flowRate);
  }
}