#pragma once

#include <inttypes.h>

#ifdef __cplusplus
extern "C"
{
#endif
    // --- GPIO direction ---
    typedef enum
    {
        HSS_GPIO_DIR_INPUT,
        HSS_GPIO_DIR_OUTPUT
    } hss_gpio_dir_t;

    // --- GPIO pull configuration as bitmask ---
    typedef enum
    {
        HSS_GPIO_PULL_NONE = 0,
        HSS_GPIO_PULL_UP = 1 << 0,
        HSS_GPIO_PULL_DOWN = 1 << 1
    } hss_gpio_pull_t;

    // --- GPIO output type ---
    typedef enum
    {
        HSS_GPIO_OTYPE_PUSHPULL = 0,
        HSS_GPIO_OTYPE_OPENDRAIN
    } hss_gpio_otype_t;

    // --- GPIO speed (platform-specific) ---
    typedef enum
    {
        HSS_GPIO_SPEED_LOW = 0,
        HSS_GPIO_SPEED_MEDIUM,
        HSS_GPIO_SPEED_HIGH,
        HSS_GPIO_SPEED_VERY_HIGH
    } hss_gpio_speed_t;

    // --- GPIO level ---
    typedef enum
    {
        HSS_GPIO_LEVEL_LOW = 0,
        HSS_GPIO_LEVEL_HIGH
    } hss_gpio_level_t;

    // --- GPIO interrupt type ---
    typedef enum
    {
        HSS_GPIO_IT_NONE = 0,
        HSS_GPIO_IT_RISING,
        HSS_GPIO_IT_FALLING,
        HSS_GPIO_IT_BOTH
    } hss_gpio_irq_type_t;

    // --- GPIO callback ---
    typedef void (*hss_gpio_callback_t)(int pin, void *context);

    // --- Full GPIO configuration ---
    typedef struct
    {
        uint16_t pin; // logical pin number
        hss_gpio_dir_t direction;
        uint8_t pull;                   // bitmask: HSS_GPIO_PULL_UP | HSS_GPIO_PULL_DOWN
        hss_gpio_otype_t otype;         // output type
        hss_gpio_speed_t speed;         // platform-specific
        hss_gpio_level_t initial_level; // for output pins
        hss_gpio_irq_type_t irq_type;   // interrupt type
        hss_gpio_callback_t callback;   // optional
        void *callback_context;         // optional
    } hss_gpio_config_t;

#ifdef __cplusplus
}
#endif