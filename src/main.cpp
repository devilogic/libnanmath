#ifdef TEST

#include <stdio.h>
#include <stdlib.h>
#include "nanmath.h"

using namespace nanan;

int main() {
	nint i;
	printf("%d\n", sizeof(nm_word));
	printf("%d\n", sizeof(nm_digit));
	printf("0x%x\n", NM_MASK);
	printf("%d\n", NM_DIGIT_BIT);
	nm_digit* s = (nm_digit*)i;
	s[0] = 0xFFFFFFFF;
	i.set_bits_counts(1);
	i.set_sign(NM_ZPOS);

	nm_digit v = 2;
	nint result;
	i.nm_mul_d(v, result);
	nm_digit* r = (nm_digit*)result;
	printf("r[0]=0x%x, r[1]=0x%x\n", r[0], r[1]);
	return 0;
}


#endif
