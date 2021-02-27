#pragma once

#include "stdint.h"

class GpioBase {
 public:
  virtual void PinSet(uint8_t pin) = 0;

  ~GpioBase() {}
};
