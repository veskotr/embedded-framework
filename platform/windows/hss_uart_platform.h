// platform/windows/uart_platform.h
#pragma once
#include "hss_uart_types.h"
#include "hss_error.h"

hss_error_t uart_init_hw(int port, const uart_config_t *cfg, const uart_platform_ext_t *ext);
hss_error_t uart_write_hw(int port, const char *data, int len);
hss_error_t uart_read_hw(int port, char *buffer, int max_len);