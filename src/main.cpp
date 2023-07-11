#include <Arduino.h>
#include <Display.h>

Display display;

void setup()
{
  Serial.begin(MONITOR_SPEED);
  display.init();
}

void loop()
{
  display.update(random(0, 50), random(0, 50));
  delay(2000);
}