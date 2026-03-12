#pragma once

#include "hss_gpio_types.h"
#include "hss_error.h"

#ifdef __cplusplus
extern "C" {
#endif

hss_error_t hss_gpio_init(const hss_gpio_config_t* cfg);
hss_error_t hss_gpio_deinit(int pin);
hss_error_t hss_gpio_write(int pin, hss_gpio_level_t level);
hss_error_t hss_gpio_read(int pin, hss_gpio_level_t* level);

// --- API: batch initialization ---
hss_error_t hss_gpio_init_batch(const hss_gpio_config_t* cfg_array, size_t count);

#ifdef __cplusplus
}
#endif