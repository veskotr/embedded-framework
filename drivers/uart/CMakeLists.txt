file(GLOB_RECURSE UART_SOURCES "src/*.c")
add_library(hss_uart_driver STATIC ${UART_SOURCES})

target_include_directories(hss_uart_driver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(hss_uart_driver PUBLIC hss_common hss_platform)