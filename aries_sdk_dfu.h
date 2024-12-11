#ifndef _ARIES_SDK_DFU_HH_
#define _ARIES_SDK_DFU_HH_

#ifdef __cplusplus
extern "C" {
#endif

#include "defines.h"   ///< Include necessary definitions and macros
#include "port_def.h"  ///< Include port definitions

/**
 * @brief Starts the Device Firmware Update (DFU) process.
 * 
 * This function initiates the DFU process, preparing the device for firmware update.
 */
void aries_sdk_dfu_start(void);

/**
 * @brief Enters the DFU update loop.
 * 
 * This function handles the DFU process loop, where the actual firmware update takes place.
 * It should be called repeatedly until the DFU process is completed.
 */
void aries_sdk_dfu_loop(void);

/**
 * @brief Checks if the DFU process is ready to start.
 * 
 * This function checks the readiness of the system to begin the DFU process.
 * 
 * @return `true` if the DFU process is ready to start, `false` otherwise.
 */
bool aries_sdk_dfu_is_ready(void);

#ifdef __cplusplus
}
#endif
#endif // _ARIES_SDK_DFU_HH_
