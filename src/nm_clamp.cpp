#include "nanmath.h"

namespace nanan {
	void nint::nm_clamp() {
		/* 在经过数次操作后，有些被使用的位，没有被使用
		 * 这里进行缩减操作 */
		while (_data.bits_counts > 0 && 
			   _data.bits[_data.bits_counts - 1] == 0) {
			--(_data.bits_counts);
		}

		/* 没有任何使用位数,则重新设置符号标志 */
		if (_data.bits_counts == 0) {
			_data.sign = NM_ZPOS;
		}
	}
}
