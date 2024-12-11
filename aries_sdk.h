#ifndef _ARIES_SDK_HH_
#define _ARIES_SDK_HH_

#ifdef __cplusplus
extern "C" {
#endif

#include "aries_sdk_cdc.h"   ///< Includes functionalities related to the Communications Device Class (CDC)
#include "aries_sdk_dfu.h"   ///< Includes functionalities related to Device Firmware Update (DFU)
#include "user_i2c_drv.h"    ///< Includes user-defined I2C driver interfaces
#include "user_iap_drv.h"    ///< Includes user-defined In-Application Programming (IAP) driver interfaces

/// The version of the Aries SDK
#define ARIES_SDK_VERSION "0.0.1"

/// Initializes the Aries SDK
///
/// This function initializes the I2C interface by calling the user-defined I2C initialization function.
__ARIES_SDK_STATIC_INLINE void aries_sdk_init(void)
{
    user_i2c_init(); ///< Initializes the I2C interface, ensuring I2C communication is available
}

/// Loads and executes the application
///
/// This function jumps to the application start address by calling the user-defined IAP jump function to execute the application.
__ARIES_SDK_STATIC_INLINE void aries_sdk_load_app(void)
{
    user_iap_jump(); ///< Jumps to the application start address to execute the application
}

#ifdef __cplusplus
}
#endif

#endif // _ARIES_SDK_HH_
