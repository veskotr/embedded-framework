add_library(hss_board STATIC hss_board.c)
target_include_directories(hss_board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(hss_board PUBLIC hss_platform)