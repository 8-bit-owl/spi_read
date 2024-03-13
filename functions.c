#include <stdint.h>

// Define the MMC5983 PRODUCT_ID value
#define MMC5983_PRODUCT_ID 0x30

// Declare the SPI_ISR function
void SPI_ISR(void);

// Volatile buffer to store the received data
volatile uint8_t buffer[1];

// Function to start the SPI transfer for MMC5983 PRODUCT_ID request
void start_SPI_MMC5983_PRODUCT_ID_request(void) {
    // Initialize SPI communication
    initialize_SPI();

    // Set up the SPI transfer
    set_SPI_transfer_mode(SPI_MODE_NON_BLOCKING);
    set_SPI_transfer_data(MMC5983_PRODUCT_ID_REGISTER_ADDRESS);
    set_SPI_receive_buffer(buffer, sizeof(buffer));

    // Start the SPI transfer
    start_SPI_transfer();
}

// SPI Interrupt Service Routine
void SPI_ISR(void) {
    // Get the received data from the SPI buffer
    uint8_t single_byte = get_SPI_received_data();
    
    // Store the received data in the volatile buffer
    

    // Check if the received data matches the MMC5983 PRODUCT_ID
    if (received_data == MMC5983_PRODUCT_ID) {
        printf("MMC5983 sensor detected\n");
        data_read_callback(&buffer[i]);
    } else {
        printf("MMC5983 sensor not detected\n");
    }
}


void TIMER_ISR() {
}
void SPI_ISR() {
}