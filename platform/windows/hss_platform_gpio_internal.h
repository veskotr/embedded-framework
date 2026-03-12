#pragma once

#include "hss_gpio_types.h"

typedef struct 
{
    int pin;
    hss_gpio_dir_t direction;
    hss_gpio_pull_t pull;
    hss_gpio_otype_t otype;
    hss_gpio_speed_t speed;
    hss_gpio_irq_type_t irq_type;
    hss_gpio_callback_t callback;
    void *callback_context;
    bool initialized;
    hss_gpio_level_t level; // Simulated level for testing
} hss_gpio_context_t;

extern hss_gpio_context_t hss_gpio_contexts[];
