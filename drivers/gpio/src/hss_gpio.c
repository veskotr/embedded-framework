#include <stdio.h>
#include "hss_gpio.h"
#include "hss_platform_gpio.h"

hss_error_t hss_gpio_init(const hss_gpio_config_t *cfg)
{
    
}
hss_error_t hss_gpio_deinit(int pin)
{
}
hss_error_t hss_gpio_write(int pin, hss_gpio_level_t level)
{
}
hss_error_t hss_gpio_read(int pin, hss_gpio_level_t *level)
{
}

hss_error_t hss_gpio_init_batch(const hss_gpio_config_t *cfg_array, size_t count)
{
}