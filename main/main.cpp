#include <stdio.h>
#include "AD5626.hpp"

extern "C" void app_main(void)
{
    AD5626 AD5626;
    AD5626.init();

    while (true)
    {
        for(uint16_t i = 0; i < 4096 ; i++){
            AD5626.writeVoltage(i);
            vTaskDelay(10 / portTICK_PERIOD_MS);
        }
    }
    
}