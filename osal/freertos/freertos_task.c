#include "hss_osal_task.h"
#include "FreeRTOS.h"
#include "task.h"

// -------------------- TASKS --------------------

hss_error_t osal_task_create(osal_task_t* task,
                             osal_task_func_t func,
                             const char* name,
                             uint32_t stack_size,
                             uint32_t priority,
                             void* params)
{
    if (!task || !func) return (hss_error_t){.code = HSS_ERROR_INVALID_ARG, .platform_code = 0};

    TaskHandle_t handle = NULL;
    BaseType_t res = xTaskCreate(func, name, stack_size, params, priority, &handle);
    if (res != pdPASS) return (hss_error_t){.code = HSS_ERROR_GENERIC, .platform_code = 0};
    *task = handle;
    return (hss_error_t){.code = HSS_OK, .platform_code = 0};
}

hss_error_t osal_task_delete(osal_task_t task)
{
    if (!task) return (hss_error_t){.code = HSS_ERROR_INVALID_ARG, .platform_code = 0};
    vTaskDelete((TaskHandle_t)task);
    return (hss_error_t){.code = HSS_OK, .platform_code = 0};
}

// -------------------- SUSPEND / RESUME --------------------

hss_error_t osal_task_suspend(osal_task_t task)
{
    if (!task) return (hss_error_t){.code = HSS_ERROR_INVALID_ARG, .platform_code = 0};
    vTaskSuspend((TaskHandle_t)task);
    return (hss_error_t){.code = HSS_OK, .platform_code = 0};
}

hss_error_t osal_task_resume(osal_task_t task)
{
    if (!task) return (hss_error_t){.code = HSS_ERROR_INVALID_ARG, .platform_code = 0};
    vTaskResume((TaskHandle_t)task);
    return (hss_error_t){.code = HSS_OK, .platform_code = 0};
}

// ISR variant
hss_error_t osal_task_resume_from_isr(osal_task_t task)
{
    if (!task) return (hss_error_t){.code = HSS_ERROR_INVALID_ARG, .platform_code = 0};
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    vTaskResumeFromISR((TaskHandle_t)task);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    return (hss_error_t){.code = HSS_OK, .platform_code = 0};
}

// -------------------- DELAY --------------------

void osal_task_delay(uint32_t ms)
{
    vTaskDelay(pdMS_TO_TICKS(ms));
}

// -------------------- TASK NOTIFICATIONS --------------------

hss_error_t osal_task_notify_give(osal_task_t task)
{
    if (!task) return (hss_error_t){.code = HSS_ERROR_INVALID_ARG, .platform_code = 0};
    BaseType_t res = xTaskNotifyGive((TaskHandle_t)task);
    return (res == pdFAIL) ? (hss_error_t){.code = HSS_ERROR_GENERIC, .platform_code = 0} : (hss_error_t){.code = HSS_OK, .platform_code = 0};
}

hss_error_t osal_task_notify_give_from_isr(osal_task_t task)
{
    if (!task) return (hss_error_t){.code = HSS_ERROR_INVALID_ARG, .platform_code = 0};
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    BaseType_t res = xTaskNotifyGiveFromISR((TaskHandle_t)task, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    return (res == pdFAIL) ? (hss_error_t){.code = HSS_ERROR_GENERIC, .platform_code = 0} : (hss_error_t){.code = HSS_OK, .platform_code = 0};
}

// Wait for notification (blocks up to timeout_ms)
uint32_t osal_task_notify_take(uint32_t timeout_ms)
{
    return ulTaskNotifyTake(pdTRUE, pdMS_TO_TICKS(timeout_ms));
}