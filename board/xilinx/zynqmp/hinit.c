#include <linux/types.h>
#include <common.h>
#include <asm-generic/gpio.h>

void gpio_init(void)
{
        gpio_request(40, "usb3_reset");

        gpio_direction_output(40, 1);

        gpio_set_value(40, 0);

        mdelay(100);

        gpio_set_value(40, 1);
}

void hw_init(void)
{
        gpio_init();
}

