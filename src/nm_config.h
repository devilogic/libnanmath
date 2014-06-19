#ifndef __LIBNANMATH_NM_CONFIG_H__
#define __LIBNANMATH_NM_CONFIG_H__

#include <stdio.h>

#ifdef NM_DIGIT
#if NM_DIGIT == 8
typedef unsigned char        nm_digit;
typedef unsigned short       nm_word;
#elif NM_DIGIT == 16
typedef unsigned short       nm_digit;
typedef unsigned int         nm_word;
#elif NM_DIGIT == 32
typedef unsigned int         nm_digit;
typedef unsigned long long   nm_word;
#else
#error please define NM_DIGIT on 8/16/32 only
#endif
#else
#error please define NM_DIGIT in Makefile
#endif

/* 一个CHAR的长度 */
#ifndef CHAR_BIT
#define CHAR_BIT      8
#endif

/* 自动设置位数,忽略了标志位 */
#ifndef NM_DIGIT_BIT
#define NM_DIGIT_BIT  ((int)(CHAR_BIT*sizeof(nm_digit)-1))
#endif

/* 位掩码 */
#define NM_MASK  ((nm_digit)1<<((nm_digit)NM_DIGIT_BIT))-((nm_digit)1)
#define NM_DIGIT_MAX NM_MASK

/* 组合队列位数 */
#define NM_WARRAY (1 << (sizeof(nm_word) * CHAR_BIT - 2 * NM_DIGIT_BIT + 1))

/* 预定义精密度位 */
#ifndef NM_PREC
	#ifndef NM_LOW_MEM					/* 内存小的时候,使用 */
		#define NM_PREC                 32
	#else
		#define NM_PREC                 8
	#endif   
#endif

/* 开启扩展函数 */
#define NM_OP_EQ
#define NM_OP_PTR
#define NM_ERROR_TO_STRING

/* 编译选项 */
#define UNUSED __attribute__((unused))


#endif
