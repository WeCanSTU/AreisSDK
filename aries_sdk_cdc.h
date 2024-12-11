#ifndef _ARIES_SDK_CDC_HH_
#define _ARIES_SDK_CDC_HH_

#ifdef __cplusplus
extern "C" {
#endif

#include "defines.h"  ///< Includes necessary definitions and macros

/**
 * @brief Reads data from the CDC interface.
 * 
 * This function reads data from the Communications Device Class (CDC) interface into a buffer.
 * 
 * @param[out] pBuffer Pointer to the buffer where the read data will be stored.
 * @param[in] length The maximum number of bytes to read.
 * 
 * @return The actual number of bytes read from the CDC interface.
 */
uint32_t aries_sdk_cdc_read(uint8_t *pBuffer, uint32_t length);

/**
 * @brief Writes data to the CDC interface.
 * 
 * This function writes data from a buffer to the Communications Device Class (CDC) interface.
 * 
 * @param[in] pBuffer Pointer to the buffer containing the data to be written.
 * @param[in] length The number of bytes to write.
 * 
 * @return The actual number of bytes written to the CDC interface.
 */
uint32_t aries_sdk_cdc_write(const uint8_t *pBuffer, uint32_t length);

/**
 * @brief Gets the number of bytes available in the CDC buffer.
 * 
 * This function returns the number of bytes currently available in the CDC interface buffer.
 * 
 * @return The number of bytes available to read.
 */
uint32_t aries_sdk_cdc_get_length(void);

#ifdef __cplusplus
}
#endif

#endif // _ARIES_SDK_CDC_HH_
