#pragma once
#include <inttypes.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        UART_PARITY_NONE,
        UART_PARITY_EVEN,
        UART_PARITY_ODD
    } uart_parity_t;
    typedef enum
    {
        UART_STOP_BITS_1,
        UART_STOP_BITS_2
    } uart_stop_bits_t;
    typedef enum
    {
        UART_FLOW_NONE,
        UART_FLOW_RTS_CTS
    } uart_flow_control_t;

    typedef struct
    {
        uint32_t baud_rate;
        uint8_t data_bits;
        uart_stop_bits_t stop_bits;
        uart_parity_t parity;
        uart_flow_control_t flow_control;
        int tx_pin;
        int rx_pin;
    } uart_config_t;

    // Optional platform-specific extensions (ESP-IDF, STM32, RS-485)
    typedef struct
    {
        int rs485_dir_pin;  // GPIO controlling RS-485 transmit/receive
        bool rs485_invert;  // invert TX/RX for RS-485
        int rx_buffer_size; // optional receive buffer size
        int tx_buffer_size; // optional transmit buffer size
        bool half_duplex;   // true for half-duplex RS-485
    } uart_platform_ext_t;

#ifdef __cplusplus
}
#endif