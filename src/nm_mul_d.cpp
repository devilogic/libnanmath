#include "nanmath.h"

namespace nanan {

	int nint::nm_mul_d(nm_digit v, nint& result) {
		nm_digit u, *tmpa, *tmpc;
		nm_word  r;
		unsigned ix, res, olduse;

		/* 确定r有足够的空间容纳 _data * v */
		if (result.get_alloc_size() < _data.bits_counts + 1) {
			if ((res = result.nm_grow(_data.bits_counts + 1)) != NM_SUCCESS) {
				return res;
			}
		}

		olduse = result.get_bits_counts();
		result.set_sign(_data.sign);
		tmpa = _data.bits;
		tmpc = (nm_digit*)result;

		/* 0进位 */
		u = 0;

		/* 这里扩展成一个字的乘法,两个digit相乘最大超不过两个digit所占的所有位 
		 * 循环便利所有被乘数所有的digit,并且依次与乘数v相乘法,并将进位与高一位
		 * 的digit相加,这里一个digit只取digit-1二进制位,最高位作为符号位。把高
		 * 于digit-1位的所有值都当作进位
		 */
		for (ix = 0; ix < _data.bits_counts; ix++) {
			/* 进行一位的乘法并加上进位 */
			r = ((nm_word) u) + ((nm_word)*tmpa++) * ((nm_word)v);

			/* 一个digit只采用digit-1有效位 */
			*tmpc++ = (nm_digit) (r & ((nm_word) NM_MASK));

			/* 设置下一轮进位 */
			u = (nm_digit) (r >> ((nm_word)NM_DIGIT_BIT));
		}

		/* 增加最后一次的进位 */
		*tmpc++ = u;
		++ix;

		/* 清0旧的结果最高位 */
		while (ix++ < olduse) {
			*tmpc++ = 0;
		}

		/* 设置使用后的位数 */
		result.set_bits_counts(_data.bits_counts + 1);
		result.nm_clamp();

		return NM_SUCCESS;
	}

	int nint::nm_mul_d(nm_digit v) {
		return nm_mul_d(v, *this);
	}
}
