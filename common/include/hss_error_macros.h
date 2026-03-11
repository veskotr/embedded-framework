#pragma once

#define _HSS_ERR_EVAL(expr) ({ common_error_t _err = (expr); _err; })


#define _HSS_ERR_CHECK_RET(err) do { if (!hss_is_ok(err)) return err; } while(0)


#define _HSS_ERR_LOG(err, msg) do { \
    if (!hss_is_ok(err)) { \
        printf("ERROR: %s: %s (code %d)\n", msg, hss_err_to_str(err), err.platform_code); \
    } \
} while(0)


#define _HSS_ERR_LOG_FMT(err, fmt, ...) do { \
    if (!hss_is_ok(err)) { \
        printf("ERROR: " fmt ": %s (code %d)\n", __VA_ARGS__, hss_err_to_str(err), err.platform_code); \
    } \
} while(0)

#define HSS_CHECK_ERR(expr) _HSS_ERR_CHECK_RET(_HSS_ERR_EVAL(expr))


#define HSS_CHECK_ERR_LOG(expr, msg) do { \
    common_error_t _err = _HSS_ERR_EVAL(expr); \
    _HSS_ERR_LOG(_err, msg); \
    _HSS_ERR_CHECK_RET(_err); \
} while(0)

#define HSS_CHECK_ERR_LOG_FMT(expr, fmt, ...) do { \
    common_error_t _err = _HSS_ERR_EVAL(expr); \
    _HSS_ERR_LOG_FMT(_err, fmt, __VA_ARGS__); \
    _HSS_ERR_CHECK_RET(_err); \
} while(0)


#define HSS_CHECK_ERR_CALL(fn_call) HSS_CHECK_ERR(fn_call)
#define HSS_CHECK_ERR_LOG_CALL(fn_call, msg) HSS_CHECK_ERR_LOG(fn_call, msg)
#define HSS_CHECK_ERR_LOG_CALL_FMT(fn_call, fmt, ...) HSS_CHECK_ERR_LOG_FMT(fn_call, fmt, __VA_ARGS__)