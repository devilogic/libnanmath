#include "nanmath.h"

#ifdef NM_OP_PTR
namespace nanan {

	nint::operator nm_digit*() {
		return _data.bits;
	}
	
	nint::operator nint_data* () {
		return &_data;
	}

	nint::operator nm_digit () {
		return _data.bits[0];
	}

	nint::operator nint_data () {
		return _data;
	}
}
#endif
