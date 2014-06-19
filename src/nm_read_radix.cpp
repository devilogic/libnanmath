#include "nanmath.h"
#include <ctype.h>

// const char* _nm_s_rmap = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

namespace nanan {
	int nint::nm_read_radix(const char* str UNUSED, int radix UNUSED) {
		// unsigned y, res, neg;
		// char ch;

		// /* 清0 */
		// nm_zero();

		// /* 确定根基是否正确 */
		// if (radix < 2 || radix > 64) {
		// 	_errno = NM_ERROR_VAL;
		// 	return NM_ERROR;
		// }

		// /* 判断符号,是正还是负 */
		// if (*str == '-') {
		// 	++str;
		// 	neg = NM_NEG;
		// } else {
		// 	neg = NM_ZPOS;
		// }
  
		// /* 处理字符串中的每一个位 */
		// while (*str) {
		// 	ch = (char) ((radix < 36) ? toupper((int) *str) : *str);
		// 	/* 在_nm_s_rmap图中进行匹配,y为转换过来的数 */
		// 	for (y = 0; y < 64; y++) {
		// 		if (ch == _nm_s_rmap[y]) {
		// 			break;
		// 		}
		// 	}

		// 	/* 如果字符在map中找到并且小于给定的radix，加它到这个数或者退出循环 */
		// 	if (y < radix) {
		// 		/* 乘以基数 */
		// 		if ((res = nm_mul_d((nm_digit)radix)) != NM_SUCCESS) {
		// 			return res;
		// 		}
				
		// 		/* 增加它的值 */
		// 		if ((res = nm_add_d((nm_digit)y)) != NM_SUCCESS) {
		// 			return res;
		// 		}
		// 	} else {
		// 		break;
		// 	}
		// 	++str;
		// }
		
		// /* 设置标志位 */
		// if (nm_iszero() != 1) {
		// 	_data.sign = neg;
		// }
		return NM_SUCCESS;
	}
}
