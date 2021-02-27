cmake_minimum_required(VERSION 3.6)
project (nrf52832_test C CXX ASM)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY)
set(OBJCOPY arm-none-eabi-objcopy)
set(SIZE arm-none-eabi-size)
set(NM arm-none-eabi-nm)
set(OPT_FLAGS "-g -O0")

set(PROJ_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../")
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../")

set(CMAKE_C_FLAGS "${OPT_FLAGS} -fpermissive -fno-builtin -Wall -fdata-sections -ffunction-sections -fno-strict-aliasing -fshort-enums")
set(CMAKE_CXX_FLAGS "${OPT_FLAGS} -fpermissive -fno-rtti -fno-builtin -Wall -std=c++11 -fdata-sections -ffunction-sections")

find_package(PkgConfig)
pkg_check_modules(GTEST "gtest" REQUIRED)
pkg_check_modules(GMOCK "gmock" REQUIRED)

# test files
set (USER_SRCS "${TEST_DIR}/src/main_test.cpp")
set (USER_SRCS ${USER_SRCS} "${TEST_DIR}/src/gpio_test.cpp")

# files from the real application
# set (USER_SRCS ${USER_SRCS} "${PROJ_DIR}/src/gpio.cpp")

include_directories(
                    ${PROJ_DIR}/inc
                    ${TEST_DIR}/inc
                   )

add_executable(${PROJECT_NAME}.out ${USER_SRCS})

target_link_libraries(${PROJECT_NAME}.out c ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)

