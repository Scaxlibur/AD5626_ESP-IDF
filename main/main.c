#include <stdio.h>
#include "AD5626.h"

/*
#define MOSIpin GPIO_NUM_25
#define SCLKpin GPIO_NUM_5
#define SYNCpin GPIO_NUM_2
#define LDACpin GPIO_NUM_21

#define SPI_HOST SPI2_HOST
*/

void app_main(void)
{
    AD5626_init(GPIO_NUM_25, GPIO_NUM_5, GPIO_NUM_2, GPIO_NUM_21, SPI2_HOST);

    while (true)
    {
        for(uint16_t i = 0; i < 4096 ; i++){
            AD5626_writeValue(i);
            vTaskDelay(50 / portTICK_PERIOD_MS);
        }
    }
}