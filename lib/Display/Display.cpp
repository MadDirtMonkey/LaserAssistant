#include "Display.h"
#include "../../src/Configuration.h"

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SSD1306_NO_SPLASH

Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

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

  screen.setTextSize(1);      // Normal 1:1 pixel scale
  screen.setTextColor(WHITE); // Draw white text
}

void Display::update(int temperature, int flowRate)
{
  screen.clearDisplay();
  screen.setCursor(0, 0); // Start at top-left corner
  screen.printf("Temperature: %i%cC\n", temperature, (char)247);
  screen.printf("Flow: %iL/min\n", flowRate);
  screen.display();
}