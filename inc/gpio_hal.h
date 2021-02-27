#pragma once

#include "gpio_base.h"

class GpioHAL : public GpioBase {
 public:
  void PinSet(uint8_t pin);

  GpioHAL() {}
  ~GpioHAL() {}
};
