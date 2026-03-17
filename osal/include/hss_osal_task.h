#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "hss_error.h"

#ifdef __cplusplus
extern "C" {
#endif

// Task handle
typedef void* osal_task_t;
typedef void (*osal_task_func_t)(void* params);

// Task functions
hss_error_t osal_task_create(osal_task_t* task,
                             osal_task_func_t func,
                             const char* name,
                             uint32_t stack_size,
                             uint32_t priority,
                             void* params);

hss_error_t osal_task_delete(osal_task_t task);

// Suspend/resume
hss_error_t osal_task_suspend(osal_task_t task);
hss_error_t osal_task_resume(osal_task_t task);

// ISR-safe suspend/resume
hss_error_t osal_task_resume_from_isr(osal_task_t task);

// Delay
void osal_task_delay(uint32_t ms);

// Task notifications
hss_error_t osal_task_notify_give(osal_task_t task);
hss_error_t osal_task_notify_give_from_isr(osal_task_t task);
uint32_t    osal_task_notify_take(uint32_t timeout_ms);

#ifdef __cplusplus
}
#endif