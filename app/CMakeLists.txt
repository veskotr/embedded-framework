add_executable(app main.c)
target_link_libraries(app PRIVATE hss_board hss_gpio_driver hss_uart_driver hss_platform)