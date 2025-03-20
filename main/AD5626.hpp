#pragma once

#include "driver/spi_master.h"
#include "driver/gpio.h"

#define MOSIpin GPIO_NUM_25
#define MISOpin -1
#define SCLKpin GPIO_NUM_5
#define SYNCpin GPIO_NUM_2

#define SPI_HOST SPI2_HOST

class AD5626{
    private:
    spi_bus_config_t spi_bus_config = {
        .mosi_io_num = MOSIpin,
        .miso_io_num = MISOpin,
        .sclk_io_num = SCLKpin,
        .flags = SPICOMMON_BUSFLAG_MASTER,
    };
    spi_device_interface_config_t interface_config = {
        .command_bits = 0,
        .address_bits = 0,
        .mode = 3,
        .clock_speed_hz = 1*1000*1000,
        .spics_io_num = SYNCpin,
        .queue_size = 6,
    };
    spi_transaction_t spi_trans;

    public:
    spi_device_handle_t AD5626handle = NULL;

    AD5626();
    ~AD5626();
    void init();
    void writeVoltage(uint16_t voltage);
};