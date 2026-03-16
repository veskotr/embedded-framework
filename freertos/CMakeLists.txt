include(FetchContent)

#add_library(freertos_config INTERFACE)
#target_include_directories(freertos_config INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/freertos/config)

set(FREERTOS_HEAP "4" CACHE STRING "" FORCE)
set(FREERTOS_PORT "MSVC_MINGW" CACHE STRING "" FORCE)

# Fetch FreeRTOS-Kernel
FetchContent_Declare(
    freertos_kernel
    GIT_REPOSITORY https://github.com/FreeRTOS/FreeRTOS-Kernel.git
    GIT_TAG V11.2.0
)
FetchContent_MakeAvailable(freertos_kernel)
