#include "defines.h"        // Include for general definitions used throughout the file
#include "port_def.h"       // Port-specific definitions, likely includes hardware-specific configurations
#include "user_iap_drv.h"   // Header for IAP driver definitions
#include "crc32.h"          // Header for CRC32 calculation functions

#define APP_ADDR            							(0x08004000)  // Starting address of the application
#define APP_FLASH_SIZE            						(0x08006000 - APP_ADDR)  // Total size of the application flash space
#define FLASH_PAGE_SIZE       							(0x80)  // Size of a single flash page
#define DFU_BUFFER_MAX_SIZE          					1024  // Maximum size of the DFU (Device Firmware Upgrade) buffer

typedef void (*JumpFun)(void);  // Define a function pointer type for jumping to application

JumpFun jumpToApp;  // Declare a function pointer for jumping to the application

#if defined(__CC_ARM)  // ARM Compiler 5 (armcc)
__align(4) uint8_t cbBlock[DFU_BUFFER_MAX_SIZE] = {0};  // Buffer for IAP operations, aligned to 4 bytes
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)  // ARM Compiler 6 (armclang)
uint8_t cbBlock[DFU_BUFFER_MAX_SIZE] __attribute__((aligned(4))) = {0};  // Buffer for IAP operations, aligned to 4 bytes
#elif defined(__GNUC__)  // GCC
uint8_t cbBlock[DFU_BUFFER_MAX_SIZE] __attribute__((aligned(4))) = {0};  // Buffer for IAP operations, aligned to 4 bytes
#else
uint8_t cbBlock[DFU_BUFFER_MAX_SIZE] = {0};  // Default buffer initialization
#endif

static IapBuffer iapBuffer = 
{
    .pBlock = cbBlock,  // Pointer to the data block used in IAP
    .blockSize = DFU_BUFFER_MAX_SIZE  // Size of the IAP block
};

/**
 * @brief Jumps to the application code address.
 * 
 * This function sets up the stack pointer and program counter to jump to 
 * the application code if conditions are met.
 * It is currently commented out and needs to be adjusted for your specific hardware.
 */
void sysJumpTo(uint32_t appAddr)
{
    // M0+ processor specific code. Uncomment and modify as necessary.
    /*
    if(((*(__IO uint32_t*)appAddr) & 0x2FFE0000) == 0x20000000)
    {
        NVIC->ICER[0] = 0XFFFFFFFF;  // Clear all pending interrupts
        jumpToApp = (JumpFun)*(__IO uint32_t*)(appAddr + 4);  // Set jump address
        __set_MSP(*(__IO uint32_t*)appAddr);  // Set main stack pointer
        jumpToApp();  // Execute the jump
    }
    */
}

/**
 * @brief Provides a delay in milliseconds.
 * 
 * This function needs to be implemented to suit the system's timing requirements.
 */
void user_iap_delay(uint32_t ms)
{
    // Implement delay logic here
}

/**
 * @brief Initializes the IAP buffer.
 * 
 * Sets up the IAP buffer to be used for subsequent operations.
 */
void user_iap_init(IapBuffer **pIapBuffer)
{
    *pIapBuffer = &iapBuffer;  // Point to the static IAP buffer
}

/**
 * @brief Resets the system.
 * 
 * Triggers a system reset using the NVIC system reset function.
 */
void user_iap_reset()
{
    NVIC_SystemReset();  // Reset the microcontroller
}

/**
 * @brief Jumps to the application start address.
 * 
 * Calls sysJumpTo to transfer execution to the application code.
 */
void user_iap_jump(void)
{
    sysJumpTo(APP_ADDR);  // Jump to the application address
}

/**
 * @brief Erases a section of flash memory.
 * 
 * Placeholder for the flash erase implementation.
 * @return 1 if successful, 0 otherwise.
 */
uint8_t user_iap_erase(FlashParams *params)
{			
    if (params->size == 0)
    {
        return 0;  // Return failure if size is zero
    }
    // ToDo: Implement the Flash erase function
    return 1;  // Return success if implemented
}

/**
 * @brief Programs data into flash memory.
 * 
 * Placeholder for the flash programming implementation.
 * @return 1 if successful, 0 otherwise.
 */
uint8_t user_iap_program(FlashParams *params)
{
    if(params->size == 0 || (params->addr + params->size) >= APP_FLASH_SIZE)
    {
        return 0;  // Return failure if size is zero or out of bounds
    }
    // ToDo: Implement the Flash program function
    return 1;  // Return success if implemented
}

/**
 * @brief Reads data from flash memory.
 * 
 * Placeholder for the flash read implementation.
 * @return The byte of data read.
 */
uint8_t user_iap_read(FlashParams *params)
{    
    uint8_t data;
    // ToDo: Implement the Flash read function
    return data;  // Return read data
}

/**
 * @brief Verifies the integrity of a flashed image using CRC32.
 * 
 * Compares calculated CRC32 with expected value.
 * @return 1 if CRC matches, 0 otherwise.
 */
uint8_t user_iap_verify_image(FlashVerifyParams *params)
{
    uint8_t *p = (uint8_t *)(APP_ADDR);
    if (params->len > APP_FLASH_SIZE)
    {
        return 0;  // Return failure if length is out of bounds
    }
    uint32_t calCrc = 0;
    calCrc = crc32(calCrc, (const uint8_t *)p, params->len);  // Calculate CRC
    return calCrc == params->crc32;  // Return comparison result
}

/**
 * @brief Returns the total size of the flash memory for the application.
 * 
 * @return Application flash size in bytes.
 */
uint32_t user_iap_get_flash_size(void)
{
    return APP_FLASH_SIZE;  // Return defined application flash size
}

/**
 * @brief Returns the size of a single flash memory block.
 * 
 * @return Flash block size in bytes.
 */
uint32_t user_iap_get_flash_block_size(void)
{
    return FLASH_PAGE_SIZE;  // Return defined flash page size
}
