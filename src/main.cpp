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
  int temp = random(0, 50);
  int flow = random(0, 50);

  display.update(temp, flow);
  delay(1000);
  display.showError("Coolant temp high");
  delay(1000);
}