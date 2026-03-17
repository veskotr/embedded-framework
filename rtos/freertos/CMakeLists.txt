include(FetchContent)

configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/config/FreeRTOSConfig.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config/FreeRTOSConfig.h
    @ONLY
)

add_library(freertos_config INTERFACE)
target_include_directories(freertos_config INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/freertos/config)

FetchContent_Declare(
    freertos_kernel
    GIT_REPOSITORY https://github.com/FreeRTOS/FreeRTOS-Kernel.git
    GIT_TAG V11.2.0
)
FetchContent_MakeAvailable(freertos_kernel)

target_include_directories(freertos_kernel INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/config)