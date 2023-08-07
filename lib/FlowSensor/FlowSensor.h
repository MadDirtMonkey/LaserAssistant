#ifndef FLOWSENSOR_H
#define FLOWSENSOR_H

#pragma once

class FlowSensor
{
private:
  static volatile int count;
  static void IRAM_ATTR ISR();
  unsigned long lastUpdateTime;
  float flowRate;

public:
  void init();
  float read();
};

#endif