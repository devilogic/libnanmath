#include "nanmath.h"

namespace nanan {
	void nint::nm_zero() {
		unsigned n;
		nm_digit* tmp;

		_data.bits_counts = 0;
		_data.sign = NM_ZPOS;
		
		tmp = _data.bits;
		for (n = 0; n < _data.alloc_size; n++) {
			*tmp++ = 0;
		}
	}
}
