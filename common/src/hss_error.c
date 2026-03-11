#include "hss_error.h"

static const char* COMMON_ERR_STRINGS[] = {
    [HSS_ERROR_OK]        = "OK",
    [HSS_ERROR_GENERIC]   = "Generic error",
    [HSS_ERROR_INVALID_ARG] = "Invalid argument",
    [HSS_ERROR_TIMEOUT]   = "Timeout",
    [HSS_ERROR_MEMORY]    = "Out of memory",
};

const char* common_err_to_str(hss_error_t err) {
    if (err.code >= 0 && err.code < sizeof(COMMON_ERR_STRINGS)/sizeof(COMMON_ERR_STRINGS[0])) {
        const char* str = COMMON_ERR_STRINGS[err.code];
        return str ? str : "Unknown error";
    }
    return "Unknown error";
}

bool hss_is_ok(hss_error_t err)
{
    return err.code == HSS_ERROR_OK;
}