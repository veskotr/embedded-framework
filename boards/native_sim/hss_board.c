#include <stdio.h>
#include "hss_board.h"
#include "hss_platform.h"

void board_init(void)
{
    platform_init();
    printf("Board initialized (native simulation)\n");
}