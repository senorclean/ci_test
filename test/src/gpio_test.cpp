#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ostream>

#include "mock_gpio_hal.h"

#include "gpio.h"

using ::testing::_;

class GpioTests : public testing::Test {
 public:
  MockGpioHAL* mock_gpio_hal;

  Gpio* gpio_dev;

 protected:
  void SetUp() override {

    mock_gpio_hal = new MockGpioHAL;
    gpio_dev = new Gpio(mock_gpio_hal);
  }

  void TearDown() override {
    delete mock_gpio_hal;
    delete gpio_dev;
  }
};

TEST_F(GpioTests, AlwaysPasses) {
  // setup

  // expect
  EXPECT_CALL(*mock_gpio_hal, PinSet(0))
    .Times(1);

  gpio_dev->PinSet(0);
}

// TEST_F(GpioTests, AlwaysFails) {
//   // setup
// 
//   // expect
//   EXPECT_CALL(*mock_gpio_hal, PinSet(0))
//     .Times(1);
// 
//   gpio_dev->PinSet(1);
// }
