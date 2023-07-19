#include <Arduino.h>
#include <Display.h>
#include <Thermistor.h>

Display display;
Thermistor thermistor;

unsigned long lastUpdateTime = 0;

void setup()
{
  Serial.begin(MONITOR_SPEED);
  display.init();
  thermistor.init();
  lastUpdateTime = millis();
}

void loop()
{
  // Check if it's time for an update
  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime > 1000 || currentTime < lastUpdateTime)
  {
    lastUpdateTime = currentTime; // Update the last update time

    float res = thermistor.read();

    display.update(res);
  }
}