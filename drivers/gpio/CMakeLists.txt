file(GLOB_RECURSE GPIO_SOURCES "src/*.c")
add_library(hss_gpio_driver STATIC ${GPIO_SOURCES})

target_include_directories(hss_gpio_driver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(hss_gpio_driver PUBLIC hss_common hss_platform)