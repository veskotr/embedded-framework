cmake_minimum_required(VERSION 4.3.0)
project(hss_osal LANGUAGES C)

# Select platform sources
if(OS_FREERTOS_ESP32)
    message(STATUS "Building for FreeRTOS on ESP32")
    file(GLOB OSAL_SOURCES "freertos_esp32/*.c")
elseif(OS_FREERTOS_GENERIC)
    message(STATUS "Building for FreeRTOS on generic platform")
    file(GLOB OSAL_SOURCES "freertos_generic/*.c")
else()
    message(FATAL_ERROR "No platform selected!")
endif()

# Define library
add_library(hss_osal STATIC ${OSAL_SOURCES})

# Include only the public API
target_include_directories(hss_osal
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the core library
target_link_libraries(hss_osal PUBLIC hss_common)