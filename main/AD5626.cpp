#include "AD5626.hpp"

AD5626::AD5626(){

}

void AD5626::writeVoltage(uint16_t voltage){
    /*
    uint8_t txbuffer[2];
    txbuffer[0] = voltage >> 8;
    txbuffer[1] = voltage >> 0;
    spi_transaction_t spi_trans = {
        .length = 12,
        .tx_buffer = txbuffer,
        //.tx_data = {txbuffer[0], txbuffer[1]},
        .rx_buffer = NULL,
    };
    */
   
    spi_trans.length = 16;
    spi_trans.tx_data[0] = (uint8_t)voltage >> 8;
    spi_trans.tx_data[1] = (uint8_t)voltage >> 0;
    spi_device_polling_transmit(AD5626handle, &spi_trans);
    
    //printf("%d\n",(int)txbuffer);
    //printf("%d\n", (int) txbuffer);
}

void AD5626::init(){
    ESP_ERROR_CHECK(spi_bus_initialize(SPI_HOST, &spi_bus_config, SPI_DMA_CH_AUTO));
    ESP_ERROR_CHECK(spi_bus_add_device(SPI_HOST, &interface_config, &AD5626handle));
}