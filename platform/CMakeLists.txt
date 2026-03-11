cmake_minimum_required(VERSION 4.3.0)
project(hss_platform LANGUAGES C)

# Select platform sources
if(PLATFORM_WINDOWS)
    message(STATUS "Building for Windows")
    file(GLOB PLATFORM_SOURCES "windows/*.c")
elseif(PLATFORM_STM32)
    message(STATUS "Building for STM32")
    file(GLOB PLATFORM_SOURCES "stm32/*.c")
elseif(PLATFORM_ESP32)
    message(STATUS "Building for ESP32")
    file(GLOB PLATFORM_SOURCES "esp32/*.c")
else()
    message(FATAL_ERROR "No platform selected!")
endif()

# Define library
add_library(hss_platform STATIC ${PLATFORM_SOURCES})

# Include only the public API
target_include_directories(hss_platform
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the core library
target_link_libraries(hss_platform PUBLIC hss_common)