cmake_minimum_required(VERSION 4.3.0)
project(hss_framework C)

set(CMAKE_C_STANDARD 11)

include(configs/rtos/freeRTOS/freertos_defaults.cmake)

# Options / unified properties
option(PLATFORM_WINDOWS "Build for Windows platform" ON)
option(PLATFORM_SIM "Use native simulation" ON)
option(USE_GPIO "Enable GPIO driver" ON)
option(USE_UART "Enable UART driver" ON)
option(OS_FREERTOS_GENERIC "Enable freeRTOS support" ON)

# Add modules
add_subdirectory(rtos)
add_subdirectory(osal)
add_subdirectory(common)
add_subdirectory(platform)
add_subdirectory(drivers)
add_subdirectory(boards)
add_subdirectory(app)
