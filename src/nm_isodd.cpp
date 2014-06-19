#include "nanmath.h"

namespace nanan {
	int nint::nm_isodd() {
		return (_data.bits_counts > 0 && 
				(_data.bits[0] & 1) == 1) ? 1 : 0;
	}
}
