file(GLOB_RECURSE COMMON_SOURCES "src/*.c")
add_library(hss_common STATIC ${COMMON_SOURCES})

target_include_directories(hss_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)