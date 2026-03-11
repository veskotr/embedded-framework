#include <stdio.h>
#include "hss_gpio.h"

void gpio_init(void) { printf("GPIO init\n"); }
void gpio_set(int pin, int value) { printf("GPIO pin %d set to %d\n", pin, value); }