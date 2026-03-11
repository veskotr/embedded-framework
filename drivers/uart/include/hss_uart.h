#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "hss_uart_types.h"
#include "hss_error.h"

#ifdef __cplusplus
extern "C"
{
#endif

    // Platform-independent API
    hss_error_t uart_init(int port, const uart_config_t *cfg, const uart_platform_ext_t *ext);
    hss_error_t uart_write(int port, const char *data, int len);
    hss_error_t uart_read(int port, char *buffer, int max_len);

#ifdef __cplusplus
}
#endif