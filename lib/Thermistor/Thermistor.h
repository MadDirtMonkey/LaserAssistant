#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#pragma once

class Thermistor
{
public:
  void init();
  float read();
};

#endif