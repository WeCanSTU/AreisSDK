#ifndef _USER_IAP_DRV_HH_
#define _USER_IAP_DRV_HH_

#ifdef __cplusplus
extern "C" {
#endif

#include "defines.h"   ///< Include general definitions
#include "port_def.h"  ///< Include port-specific definitions


/**
 * @brief Initializes the IAP system.
 *
 * @param pIapBuffer Double pointer to an IapBuffer structure. It initializes 
 *                   the buffer required for IAP operations.
 */
ext void user_iap_init(IapBuffer **pIapBuffer);

/**
 * @brief Jumps to the application code.
 *
 * This function is used to transfer control to the main application code 
 * after IAP operations are completed.
 */
ext void user_iap_jump(void);

/**
 * @brief Delays for a specified amount of time.
 *
 * @param ms Number of milliseconds to delay.
 *
 * This function provides a delay mechanism to pause execution for a 
 * specified duration.
 */
ext void user_iap_delay(uint32_t ms);

/**
 * @brief Resets the system.
 *
 * This function triggers a system reset, restarting the device.
 */
ext void user_iap_reset(void);

/**
 * @brief Erases a section of flash memory.
 *
 * @param params Pointer to a FlashParams structure containing the address 
 *               and size of the flash area to erase.
 * @return Status of the erase operation, typically 1 for success or 0 for failure.
 */
ext uint8_t user_iap_erase(FlashParams *params);

/**
 * @brief Programs flash memory with data.
 *
 * @param params Pointer to a FlashParams structure containing the target 
 *               address and data to be written to flash.
 * @return Status of the program operation, typically 1 for success or 0 for failure.
 */
ext uint8_t user_iap_program(FlashParams *params);

/**
 * @brief Reads a byte of data from flash memory.
 *
 * @param params Pointer to a FlashParams structure containing the source 
 *               address from which to read the data.
 * @return The byte of data read from the specified flash address.
 */
ext uint8_t user_iap_read(FlashParams *params);

/**
 * @brief Gets the total size of the flash memory.
 *
 * @return Total flash size in bytes.
 */
ext uint32_t user_iap_get_flash_size(void);

/**
 * @brief Gets the size of a flash memory block.
 *
 * @return Flash block size in bytes.
 */
ext uint32_t user_iap_get_flash_block_size(void);

/**
 * @brief Verifies the integrity of an image in flash memory.
 *
 * @param params Pointer to a FlashVerifyParams structure containing the 
 *               expected CRC32 or SHA1 for verification.
 * @return Status of the verification, typically 1 for success or 0 for failure.
 */
ext uint8_t user_iap_verify_image(FlashVerifyParams *params);

#ifdef __cplusplus
}
#endif
#endif // _USER_IAP_DRV_HH_
