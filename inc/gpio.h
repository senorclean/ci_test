#pragma once

#include "gpio_hal.h"

class Gpio {
 public:
  Gpio(GpioBase* m_hal) : m_hal(m_hal) {}

  void PinSet(uint8_t pin) {
    m_hal->PinSet(pin);
  }

  ~Gpio() {}

 private:
  GpioBase* m_hal;
};
