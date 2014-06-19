#include "nanmath.h"

namespace nanan {
	int nint::nm_iszero() {
		return _data.bits_counts == 0 ? 1 : 0;
	}
}
