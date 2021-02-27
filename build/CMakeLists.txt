cmake_minimum_required(VERSION 3.6)
project (nrf52832 C CXX ASM)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY)

# useful shortcuts for later
set(OBJCOPY arm-none-eabi-objcopy)
set(SIZE arm-none-eabi-size)
set(NM arm-none-eabi-nm)

# optimization level
set(OPT_FLAGS "-g -O1")

# convenient path variables
set(PROJ_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../")
set(BIN_DIR "${PROJ_DIR}/bin")

# special files
set(LINKER "${BIN_DIR}/ble_app_buttonless_dfu_gcc_nrf52.ld")
set(STARTUP "${PROJ_DIR}/startup/gcc_startup_nrf52.S")

# flags that are language-independent
set(CORE_FLAGS "--specs=nano.specs -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mabi=aapcs")

# flags for the C files
set(CMAKE_C_FLAGS "${CORE_FLAGS} ${OPT_FLAGS} -std=c99 -fno-builtin -Wall -fdata-sections -ffunction-sections -fno-strict-aliasing -fshort-enums")
# flags for the C++ files
set(CMAKE_CXX_FLAGS "${CORE_FLAGS} ${OPT_FLAGS} -fno-rtti -fno-builtin -Wall -std=c++11 -fdata-sections -ffunction-sections")
# the C++ linker is used when linking so flags are taken from toolchain file
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T${LINKER}")

# glob all of the source files
file(GLOB USER_SRCS "${PROJ_DIR}/src/*.cpp")
file(GLOB NORDIC_SRCS "${PROJ_DIR}/extern/nrf/*.c")

# add includes
include_directories(
                    ${PROJ_DIR}/inc
                    ${PROJ_DIR}/extern/nrf
                   )
                 

# link all necessary files to the executable
add_executable(${PROJECT_NAME}.out ${USER_SRCS} ${NORDIC_SRCS} ${STARTUP})

add_custom_command(TARGET ${PROJECT_NAME}.out POST_BUILD
  COMMENT "BUILDING HEX AND BIN FILES"
  # build .hex and .bin files
  COMMAND ${OBJCOPY} -O ihex ${PROJECT_NAME}.out ${PROJECT_NAME}.hex
  COMMAND ${OBJCOPY} -O binary ${PROJECT_NAME}.out ${PROJECT_NAME}.bin
  # output the size of the program
  COMMAND ${SIZE} --format=berkeley ${PROJECT_NAME}.out
  COMMENT "DONE"
)

