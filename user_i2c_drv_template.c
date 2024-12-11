#include "defines.h"
#include "port_def.h"
#include "user_i2c_drv.h"

/**
 * @brief Initializes the I2C interface.
 *
 * This function sets up the I2C hardware with the appropriate configuration
 * parameters, such as clock speed and addressing mode.
 */
void user_i2c_init(void)
{
    // Todo: Implement the I2C initialization function
    // Example pseudocode:
    // - Configure I2C clock speed
    // - Set up I2C pins for SDA and SCL
    // - Enable the I2C peripheral
}

/**
 * @brief Reads data from an I2C device.
 *
 * @param params Pointer to a TwoWireParams structure containing the device
 *               address, register address (if applicable), and buffer to store
 *               the read data.
 * @return The number of bytes successfully read.
 */
uint32_t user_i2c_read(TwoWireParams *params)
{
    uint32_t cnt = 0;
    // Todo: Implement the I2C read function
    // Example pseudocode:
    // - Start I2C communication
    // - Send device address with read flag
    // - Read data from the device into params->buffer
    // - Stop I2C communication
    // - Return the number of bytes read
    return cnt;
}

/**
 * @brief Writes data to an I2C device.
 *
 * @param params Pointer to a TwoWireParams structure containing the device
 *               address, register address (if applicable), and buffer with 
 *               data to be written.
 * @return The number of bytes successfully written.
 */
uint32_t user_i2c_write(TwoWireParams *params)
{
    uint32_t cnt = 0;
    // Todo: Implement the I2C write function
    // Example pseudocode:
    // - Start I2C communication
    // - Send device address with write flag
    // - Write data from params->buffer to the device
    // - Stop I2C communication
    // - Return the number of bytes written
    return cnt;
}
