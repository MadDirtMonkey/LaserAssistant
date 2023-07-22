#include "Display.h"
#include "../../src/Configuration.h"

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SSD1306_NO_SPLASH

Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, SCREEN_RESET_PIN);

void Display::init()
{
  Wire.begin(SDA_PIN, SCL_PIN);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
}

void Display::update(float voltage)
{
  screen.clearDisplay();

  screen.setTextSize(1);
  screen.setTextColor(WHITE);
  screen.setCursor(0, 0); // Start at top-left corner
  screen.printf("Voltage: %.2fmV\n", voltage);
  screen.display();
}