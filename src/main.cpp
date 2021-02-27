#include "gpio.h"

int main() {
  GpioHAL gpio_hal;

  Gpio gpio_dev(&gpio_hal);

  gpio_dev.PinSet(0);
}
