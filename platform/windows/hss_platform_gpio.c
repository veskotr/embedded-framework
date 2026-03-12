#include "hss_platform_gpio.h"
#include "hss_platform_gpio_internal.h"
#include <stdio.h>

hss_gpio_context_t hss_gpio_contexts[] = {0};


hss_error_t hss_platform_gpio_init(const hss_gpio_config_t *cfg)
{
    hss_gpio_context_t *context = &hss_gpio_contexts[cfg->pin];
    context->pin = cfg->pin;
    context->direction = cfg->direction;
    context->pull = cfg->pull;
    context->otype = cfg->otype;
    context->speed = cfg->speed;
    context->irq_type = cfg->irq_type;
    context->callback = cfg->callback;
    context->callback_context = cfg->callback_context;
    context->initialized = true;

    printf("[SIM] Initialized GPIO pin %d as %s\n", cfg->pin, 
        cfg->direction == HSS_GPIO_DIR_INPUT ? "INPUT" : "OUTPUT");

    return (hss_error_t){.code = HSS_ERROR_OK, .platform_code = 0};
}

hss_error_t hss_platform_gpio_deinit(int pin)
{
    hss_gpio_context_t *context = &hss_gpio_contexts[pin];
    context->pin = 0;
    context->direction = 0;
    context->pull = 0;
    context->otype = 0;
    context->speed = 0;
    context->irq_type = 0;
    context->callback = NULL;
    context->callback_context = NULL;
    context->initialized = false;

    printf("[SIM] Deinitialized GPIO pin %d\n", pin);

    return (hss_error_t){.code = HSS_ERROR_OK, .platform_code = 0};
}

hss_error_t hss_platform_gpio_write(int pin, hss_gpio_level_t level)
{
    hss_gpio_context_t *context = &hss_gpio_contexts[pin];
    if (!context->initialized || context->direction != HSS_GPIO_DIR_OUTPUT){
        return (hss_error_t){.code = HSS_ERROR_INVALID_STATE, .platform_code = 0};
    }

    context->level = level;

    printf("[SIM] GPIO pin %d set to %s\n", pin, 
        level == HSS_GPIO_LEVEL_LOW ? "LOW" : "HIGH");

    return (hss_error_t){.code = HSS_ERROR_OK, .platform_code = 0};
    
}

hss_error_t hss_platform_gpio_read(int pin, hss_gpio_level_t *level)
{
    hss_gpio_context_t *context = &hss_gpio_contexts[pin];
    if (!context->initialized || context->direction != HSS_GPIO_DIR_INPUT){
        return (hss_error_t){.code = HSS_ERROR_INVALID_STATE, .platform_code = 0};
    }

    *level = context->level;

    printf("[SIM] GPIO pin %d read as %s\n", pin, 
        *level == HSS_GPIO_LEVEL_LOW ? "LOW" : "HIGH");

    return (hss_error_t){.code = HSS_ERROR_OK, .platform_code = 0};
}

// --- API: batch initialization ---
hss_error_t hss_platform_gpio_init_batch(const hss_gpio_config_t *cfg_array, size_t count){
    for (size_t i = 0; i < count; i++){
        hss_error_t err = hss_platform_gpio_init(&cfg_array[i]);
        if (!hss_is_ok(err)){
            return err;
        }
    }
    return (hss_error_t){.code = HSS_ERROR_OK, .platform_code = 0};
}