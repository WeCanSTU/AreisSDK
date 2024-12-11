#ifndef _PORT_DEF_H_H
#define _PORT_DEF_H_H

#ifdef __cplusplus
extern "C" {
#endif

#include "defines.h"  ///< Include common definitions and macros

/**
 * @brief Represents a buffer used for In-Application Programming (IAP).
 */
typedef struct {
    uint8_t *pBlock;     ///< Pointer to the data block
    uint32_t blockSize;  ///< Size of the data block in bytes
} IapBuffer;

/**
 * @brief Represents parameters for flash operations.
 */
typedef struct {
    uint32_t addr;       ///< Starting address for the flash operation
    uint8_t* blockData;  ///< Pointer to the flash data block
    uint32_t size;       ///< Size of the data block in bytes
} FlashParams;

/**
 * @brief Contains parameters for verifying flash data.
 */
typedef struct {
    uint32_t crc32;      ///< CRC32 checksum for data verification
    uint8_t* sha1;       ///< Pointer to the SHA1 hash for data verification
    uint32_t len;        ///< Length of the data to be verified
} FlashVerifyParams;

/**
 * @brief Represents communication parameters for a two-wire interface, such as I2C.
 */
typedef struct {
    uint8_t slaveAddr;   ///< Slave device address
    uint8_t reg;         ///< Target register address
    uint8_t *pData;      ///< Pointer to the data to read/write
    uint32_t size;       ///< Size of the data to transfer in bytes
} TwoWireParams;

#ifdef __cplusplus
}
#endif
#endif // _PORT_DEF_H_H
