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

void Display::update(float temperature, float flowRate)
{
  screen.clearDisplay();

  screen.setTextSize(1);
  screen.setTextColor(WHITE);
  screen.setCursor(0, 0); // Start at top-left corner
  screen.printf("Temperature: %.2f%cC\n", temperature, (char)247);
  screen.printf("Flow: %iL/min\n", flowRate);
  screen.display();

  if (temperature > MAX_SAFE_TEMPERATURE)
  {
    delay(500);
    showError("Temperature too high");
  }
  if (temperature < MIN_SAFE_TEMPERATURE)
  {
    delay(500);
    showError("Temperature too low");
  }
}

void Display::showError(const char *errorMessage)
{
  screen.fillRect(12, 15, 104, 24, WHITE); // Draw background
  screen.setTextColor(BLACK);
  screen.setTextSize(2);
  screen.setCursor(18, 20);
  screen.println("WARNING!");

  screen.setTextSize(1);
  int msgWidth = strlen(errorMessage) * 6;                                                    // Width of error message in pixels
  int startPos = msgWidth > 127 ? 0 : (128 - msgWidth) / 2;                                   // Start position of error message
  screen.fillRect(max(0, startPos - 4), 43, msgWidth + 8, (msgWidth > 127 ? 24 : 12), WHITE); // Draw background
  screen.setCursor(startPos, 45);
  screen.println(errorMessage);

  screen.display();
}
