#ifndef _USER_I2C_DRV_HH_
#define _USER_I2C_DRV_HH_

#ifdef __cplusplus
extern "C" {
#endif

#include "defines.h"   ///< Include general definitions
#include "port_def.h"  ///< Include port-specific definitions

/**
 * @brief Initializes the I2C interface.
 *
 * This function sets up the necessary configurations to prepare the I2C 
 * hardware for communication.
 */
ext void user_i2c_init(void);

/**
 * @brief Reads data from an I2C device.
 *
 * @param params Pointer to a TwoWireParams structure containing the I2C 
 *               address, register address, and buffer for storing the read data.
 * @return Status of the read operation, typically 0 for success or an error code.
 *
 * This function performs a read operation on the I2C bus, accessing the
 * specified register of a slave device and storing the read data into the
 * provided buffer.
 */
ext uint32_t user_i2c_read(TwoWireParams *params);

/**
 * @brief Writes data to an I2C device.
 *
 * @param params Pointer to a TwoWireParams structure containing the I2C 
 *               address, register address, and buffer with data to be written.
 * @return Status of the write operation, typically 0 for success or an error code.
 *
 * This function performs a write operation on the I2C bus, sending data to the
 * specified register of a slave device from the provided buffer.
 */
ext uint32_t user_i2c_write(TwoWireParams *params);

#ifdef __cplusplus
}
#endif
#endif // _USER_I2C_DRV_HH_
