
#ifndef _CRC32_H_
#define _CRC32_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t crc32(uint32_t crc, const uint8_t *buf, uint32_t len);


#ifdef __cplusplus
}
#endif

#endif //_CRC32_H_
