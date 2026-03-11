#include "hss_board.h"
#include "hss_gpio.h"
#include "hss_uart.h"

int main(void)
{
    board_init();
    gpio_init();
    gpio_set(LED_PIN, 1);

    uart_config_t cfg = {
        .baud_rate = 115200,
        .data_bits = 8,
        .stop_bits = UART_STOP_BITS_1,
        .parity = UART_PARITY_NONE,
        .flow_control = UART_FLOW_NONE,
        .tx_pin = 1,
        .rx_pin = 2};

    uart_init(0, &cfg, NULL);
    uart_write(0, "Hello World!\n", 13);

    return 0;
}