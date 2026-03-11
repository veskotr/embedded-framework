// platform/esp32/uart_platform.c
#include "hss_uart_platform.h"
#include <stdio.h>

hss_error_t uart_init_hw(int port, const uart_config_t *cfg, const uart_platform_ext_t *ext)
{
    printf("[SIM] Initializing UART port %d\n", port);
    return (hss_error_t) {
        .code = HSS_ERROR_OK,
        .platform_code = 0
    };
}

hss_error_t uart_write_hw(int port, const char *data, int len)
{
    printf("[SIM] UART%d write: %.*s\n", port, len, data);
    return (hss_error_t) {
        .code = HSS_ERROR_OK,
        .platform_code = 0
    };
}

hss_error_t uart_read_hw(int port, char *buffer, int max_len)
{
    scanf("%s", buffer);
    return (hss_error_t) {
        .code = HSS_ERROR_OK,
        .platform_code = 0
    };
}