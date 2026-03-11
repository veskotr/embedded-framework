#pragma once

#include <inttypes.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef enum
    {
        HSS_ERROR_OK = 0,
        HSS_ERROR_GENERIC,
        HSS_ERROR_INVALID_ARG,
        HSS_ERROR_INVALID_STATE,
        HSS_ERROR_TIMEOUT,
        HSS_ERROR_MEMORY,
    } hss_error_code_t;

    typedef struct
    {
        hss_error_code_t code;
        uint32_t platform_code;
    } hss_error_t;

    bool hss_is_ok(hss_error_t err);
    const char *hss_err_to_str(hss_error_t err);

#ifdef __cplusplus
}
#endif
