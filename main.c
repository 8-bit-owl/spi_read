/*
Contains definitions of functions.

*/



#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Define the MMC5983 PRODUCT_ID value
#define MMC5983_PRODUCT_ID 0x30
volatile uint16_t buffer[1];
// Timer function to implement delay in milliseconds.
void start_SPI_MMC5983_data_read(uint8_t *buffer) {
//Not to be implemented 
}
void (*data_read_callback)(uint8_t *data)

void delay_ms(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds)
        ;
    
}
// function to generate interrupt every 1000ms
void start_timer()
{
    while(1)
    {
        delay_ms(100);
        TIMER_ISR();
    }
}
// Timer ISR
void TIMER_ISR()
{
    printf("Timer interrupt occurred 100ms\n");
}

// function to call when SPI interrupt occurs


int main()
{
    
    device_inserted_removed_callback = device_inserted_callback;
    data_read_callback = data_read_callback;

    start_timer();
    // Nothing to be written below this! 
    while(1)
    {
        ;
    }
    return 0;
}