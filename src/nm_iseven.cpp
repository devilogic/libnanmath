#include "nanmath.h"

namespace nanan {
	int nint::nm_iseven() {
		return (_data.bits_counts > 0 && 
				(_data.bits[0] & 1) == 0) ? 1 : 0;
	}
}
