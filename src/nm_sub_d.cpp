#include "nanmath.h"

namespace nanan {
	int nint::nm_sub_d(nm_digit v, nint& result) {
		return 0;
	}

	int nint::nm_sub_d(nm_digit v) {
		return nm_sub_d(v, *this);
	}
}
