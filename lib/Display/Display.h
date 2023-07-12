#ifndef DISPLAY_H
#define DISPLAY_H

#pragma once

class Display
{
public:
  void init();
  void update(float temperature, float flowRate);
  void showError(const char *errorMessage);
};

#endif