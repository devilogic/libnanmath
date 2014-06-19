#include "nanmath.h"

#ifdef NM_OP_EQ
namespace nanan {
	nint& nint::operator= (nint& v) {
		v.write(&_data);
		return *this;
	}

	nint& nint::operator= (char v UNUSED) {
		return *this;
	}

	nint& nint::operator= (short v UNUSED) {
		return *this;
	}

	nint& nint::operator= (int v UNUSED) {
		return *this;
	}

	nint& nint::operator= (long v UNUSED) {
		return *this;
	}

	nint& nint::operator= (unsigned char v UNUSED) {
		return *this;
	}

	nint& nint::operator= (unsigned short v UNUSED) {
		return *this;
	}

	nint& nint::operator= (unsigned int v UNUSED) {
		return *this;
	}

	nint& nint::operator= (unsigned long v UNUSED) {
		return *this;
	}

	nint& nint::operator= (char* v UNUSED) {
		return *this;
	}

	// nint& nint::operator= (nm_digit v) {
	// 	nm_zero();
		
	// 	_data.bits[0] = v;
	// 	_data.bits_count = 1;
	// 	_data.sign = NM_ZPOS;
		
	// 	return *this;
	// }
}

#endif
