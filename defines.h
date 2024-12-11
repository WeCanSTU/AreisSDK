#ifndef _DEFINES_H_
#define _DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>     ///< Standard input/output library
#include <stdint.h>    ///< Standard integer types
#include <stdbool.h>   ///< Boolean type and values

#define SHA1_BUFFER_SIZE                         		20  // Size of the buffer used for SHA1 (if used)

#ifndef ext
#define ext
#endif

#if defined(__CC_ARM)
    /** 
     * @brief Inline keyword for ARM Compiler.
     */
    #define __ARIES_SDK_INLINE                         __inline

    /**
     * @brief Static inline keyword for ARM Compiler.
     */
    #define __ARIES_SDK_STATIC_INLINE                  static __inline
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    /** 
     * @brief Inline keyword for ARM Compiler version 6.1 and above.
     */
    #define __ARIES_SDK_INLINE                         __inline

    /**
     * @brief Static inline keyword for ARM Compiler version 6.1 and above.
     */
    #define __ARIES_SDK_STATIC_INLINE                  static __inline
#elif defined ( __GNUC__ )
    /** 
     * @brief Inline keyword for GNU Compiler.
     */
    #define __ARIES_SDK_INLINE                        inline

    /**
     * @brief Static inline keyword for GNU Compiler.
     */
    #define __ARIES_SDK_STATIC_INLINE                 static inline
#else
    /**
     * @brief Fallback definition for inline keyword if no known compiler is detected.
     */
    #define __ARIES_SDK_INLINE

    /**
     * @brief Fallback definition for static inline keyword if no known compiler is detected.
     */
    #define __ARIES_SDK_STATIC_INLINE
#endif

/**
 * @brief Extracts the 0th byte (least significant byte) from a word.
 * 
 * @param d Word from which to extract the byte.
 * @return The least significant byte of the word.
 */
#define BYTE0(d)                                    ((BYTE)(d))

/**
 * @brief Extracts the 1st byte from a word.
 * 
 * @param d Word from which to extract the byte.
 * @return The second least significant byte of the word.
 */
#define BYTE1(d)                                    ((BYTE)((d) >> 8))

/**
 * @brief Extracts the 2nd byte from a word.
 * 
 * @param d Word from which to extract the byte.
 * @return The third least significant byte of the word.
 */
#define BYTE2(d)                                    ((BYTE)((d) >> 16))

/**
 * @brief Extracts the 3rd byte (most significant byte in a 32-bit word) from a word.
 * 
 * @param d Word from which to extract the byte.
 * @return The most significant byte of the word.
 */
#define BYTE3(d)                                    ((BYTE)((d) >> 24))

#ifdef __cplusplus
}
#endif
#endif // _DEFINES_H_
