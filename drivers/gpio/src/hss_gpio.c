#include <stdio.h>
#include "hss_gpio.h"
#include "hss_platform_gpio.h"

hss_error_t hss_gpio_init(const hss_gpio_config_t *cfg)
{
    return hss_platform_gpio_init(cfg);
}
hss_error_t hss_gpio_deinit(int pin)
{
    return hss_platform_gpio_deinit(pin);
}
hss_error_t hss_gpio_write(int pin, hss_gpio_level_t level)
{
    return hss_platform_gpio_write(pin, level);
}
hss_error_t hss_gpio_read(int pin, hss_gpio_level_t *level)
{
    return hss_platform_gpio_read(pin, level);
}

hss_error_t hss_gpio_init_batch(const hss_gpio_config_t *cfg_array, size_t count)
{
    return hss_platform_gpio_init_batch(cfg_array, count);
}