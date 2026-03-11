file(GLOB_RECURSE COMMON_SOURCES "common/*.c")

if(PLATFORM_WINDOWS)
    message(STATUS "Building for Windows")
    file(GLOB_RECURSE PLATFORM_SOURCES "windows/*.c")
    set(PLATFORM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/windows)
elseif(PLATFORM_STM32)
    message(STATUS "Building for STM32")
    file(GLOB_RECURSE PLATFORM_SOURCES "stm32/*.c")
    set(PLATFORM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/stm32)
elseif(PLATFORM_ESP32)
    message(STATUS "Building for ESP32")
    file(GLOB_RECURSE PLATFORM_SOURCES "esp32/*.c")
    set(PLATFORM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/esp32)
else()
    message(FATAL_ERROR "No platform selected!")
endif()

list(APPEND PLATFORM_SOURCES ${COMMON_SOURCES})

add_library(hss_platform STATIC ${PLATFORM_SOURCES})

target_include_directories(hss_platform PUBLIC
    ${PLATFORM_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)

target_link_libraries(hss_platform PUBLIC hss_common)
