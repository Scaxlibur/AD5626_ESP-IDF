#include "AD5626.hpp"

/**
 * @brief   构造函数，填入相应引脚参数即可
 * @param   _MOSIpin    芯片DI引脚，即数据输入引脚
 * @param   _SCLKpin    时钟引脚
 * @param   _SYNCpin    片选引脚
 * @param   _SPI_HOST   使用的SPI外设
 */
AD5626::AD5626(int _MOSIpin, int _SCLKpin, int _SYNCpin, int _SPI_HOST){
    MOSIpin = _MOSIpin;
    SCLKpin = _SCLKpin;
    SYNCpin = _SYNCpin;
    SPI_HOST = _SPI_HOST;
    init();
}

/**
 * @brief   输出值设置
 * @param   value     电压值
 * @note    范围是0-4095
 * @note    作者仅使用了1024-3071范围，即-2.5V-2.5V
 */
void AD5626::writeValue(uint16_t value){
    spi_trans.length = 16;
    spi_trans.tx_data[0] = (uint8_t)value >> 8;
    spi_trans.tx_data[1] = (uint8_t)value >> 0;
    spi_device_polling_transmit(AD5626handle, &spi_trans);
}

/**
 * @brief   初始化函数
 */
void AD5626::init(){
    ESP_ERROR_CHECK(spi_bus_initialize(SPI_HOST, &spi_bus_config, SPI_DMA_CH_AUTO));
    ESP_ERROR_CHECK(spi_bus_add_device(SPI_HOST, &interface_config, &AD5626handle));
}