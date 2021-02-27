#include "gpio_hal.h"
#include "nrf_gpio.h"

void GpioHAL::SetPin(uint8_t pin) {
  nrf_gpio_pin_set(pin);
}

