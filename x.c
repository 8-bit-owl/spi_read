

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TRUE    1
#define FALSE   0

volatile spi_transfer_complete;
volatile uint8_t LOCKED = FALSE;
//callbacks
void data_read_callback(uint16_t *data) {
    printf("Received data: 0x%02X\n", data[0]);
}


void TIMER_ISR() 
{

    printf("Timer interrupt occurred 100ms\n");
    


}
void SPI_ISR() 
{

    // Get the received data from the SPI buffer
    uint16_t received_data = get_SPI_received_data();

    // Store the received data in the volatile buffer
    buffer[0] = received_data;

    // Check if the received data matches the MMC5983 PRODUCT_ID
    if (received_data == MMC5983_PRODUCT_ID) {
        printf("MMC5983 sensor detected\n");
        *device_inserted_callback
    } else {
        printf("MMC5983 sensor not detected\n");
    }

    spi_transfer_complete = true;

}

void device_inserted_callback(bool device_inserted) {
    if (device_inserted) {
        printf("MMC5983 sensor inserted\n");
    } else {
        printf("MMC5983 sensor removed\n");
    }
}