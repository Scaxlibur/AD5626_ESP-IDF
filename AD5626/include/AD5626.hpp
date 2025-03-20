#pragma once

#include "driver/spi_master.h"
#include "driver/gpio.h"

/*
#define MOSIpin GPIO_NUM_25
#define SCLKpin GPIO_NUM_5
#define SYNCpin GPIO_NUM_2

#define SPI_HOST SPI2_HOST
*/
class AD5626{
    private:
    int MOSIpin;
    int SCLKpin;
    int SYNCpin;
    int SPI_HOST;

    spi_bus_config_t spi_bus_config;
    spi_bus_config.mosi_io_num = MOSIpin;
    spi_bus_config.miso_io_num = -1;
    spi_bus_config.sclk_io_num = SCLKpin;
    spi_bus_config.flags = SPICOMMON_BUSFLAG_MASTER;

    spi_device_interface_config_t interface_config;
    interface_config.command_bits = 0;
    interface_config.address_bits = 0;
    interface_config.mode = 3;
    interface_config.clock_speed_hz = 1*1000*1000;
    interface_config.spics_io_num = SYNCpin;
    interface_config.queue_size = 6;

    spi_transaction_t spi_trans;

    void init();

    public:
    spi_device_handle_t AD5626handle = NULL;

    AD5626(int _MOSIpin, int _SCLKpin, int _SYNCpin, int _SPI_HOST);
    ~AD5626();
    void writeValue(uint16_t value);
};