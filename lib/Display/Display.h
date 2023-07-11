#ifndef DISPLAY_H
#define DISPLAY_H

#pragma once

class Display
{
public:
  void init();
  void update(int temperature, int flowRate);
};

#endif