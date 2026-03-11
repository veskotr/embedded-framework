#include "hss_platform_uart.h"

hss_error_t uart_init(int port, const uart_config_t *cfg, const uart_platform_ext_t *ext)
{
    return uart_init_hw(port, cfg, ext);
}

hss_error_t uart_write(int port, const char *data, int len)
{
    return uart_write_hw(port, data, len);
}

hss_error_t uart_read(int port, char *buffer, int max_len)
{
    return uart_read_hw(port, buffer, max_len);
}