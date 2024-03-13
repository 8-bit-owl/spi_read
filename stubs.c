
#define MMC5983_PRODUCT_ID 0x30

void start_SPI_MMC5983_PRODUCT_ID_request(uint8_t *buffer);

void start_SPI_MMC5983_data_read(uint8_t *buffer);

void start_timer()



void main()
{
    uint8_t req_buffer[16];
    start_SPI_MMC5983_PRODUCT_ID_request(req_buffer);

    while(1)
    {
        ;
    }
}

void SPI_ISR() 
{
    while(LOCKED==TRUE)
    {
    }
    LOCKED = TRUE;
    // Get the received data from the SPI buffer
    uint16_t received_data = get_SPI_received_data();

    // Store the received data in the volatile buffer
    

    // Check if the received data matches the MMC5983 PRODUCT_ID
    if (req_buffer[15] == MMC5983_PRODUCT_ID) {
        printf("MMC5983 sensor detected\n");
        *device_inserted_callback
    } else {
        printf("MMC5983 sensor not detected\n");
    }

    spi_transfer_complete = true;
    LOCKED = FALSE;
}