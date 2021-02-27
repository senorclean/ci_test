#pragma once

#include <gmock/gmock.h>
#include "gpio_base.h"
#include <string>


// namespace gpio {

// std::ostream& operator<<(std::ostream& os, const State& val) {
//   return os << static_cast<std::underlying_type<State>::type>(val);
// }

// };


class MockGpioHAL : public GpioBase {
 public:
  MOCK_METHOD(void, PinSet, (uint8_t pin), (override));
};
