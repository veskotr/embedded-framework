#include "hss_gpio.h"
#include "hss_uart.h"

int main(void)
{

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

    hss_gpio_config_t gpio_cfg = {
        .pin = 5,
        .direction = HSS_GPIO_DIR_OUTPUT,
        .pull = HSS_GPIO_PULL_NONE,
        .otype = HSS_GPIO_OTYPE_PUSHPULL,
        .speed = HSS_GPIO_SPEED_LOW,
        .irq_type = HSS_GPIO_IT_NONE,
        .callback = NULL,
        .callback_context = NULL
    };

    hss_gpio_init(&gpio_cfg);
    hss_gpio_write(5, HSS_GPIO_LEVEL_HIGH);

    hss_gpio_write(5, HSS_GPIO_LEVEL_LOW);

    return 0;
}