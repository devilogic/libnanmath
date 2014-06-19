#include "nanmath.h"

namespace nanan {

	int nint::nm_add_d(nm_digit v, nint& result) {
		nm_digit u, *tmpa, *tmpc;
		nm_word  r;
		unsigned ix, res, olduse;

		/* 确定r有足够的空间容纳 _data * v */
		if (result.get_alloc_size() < _data.bits_counts + 1) {
			if ((res = result.nm_grow(_data.bits_counts + 1)) != NM_SUCCESS) {
				return res;
			}
		}

		/* 如果被加数是负数并且绝对值大于加数v, 
		   调用result = 被加数的绝对值 - 加数v  */
		if (_data.sign == NM_NEG && 
			(_data.bits_counts > 1 || _data.bits[0] >= v)) {
			/* temporarily fix sign of a */
			a->sign = MP_ZPOS;
			
			/* c = |a| - b */
			res = mp_sub_d(a, b, c);
			
			/* fix sign  */
			a->sign = c->sign = MP_NEG;

			/* clamp */
			mp_clamp(c);
			
			return res;
		}

		/* old number of used digits in c */
		oldused = c->used;

		/* sign always positive */
		c->sign = MP_ZPOS;

		/* source alias */
		tmpa    = a->dp;

		/* destination alias */
		tmpc    = c->dp;

		/* if a is positive */
		if (a->sign == MP_ZPOS) {
			/* add digit, after this we're propagating
			 * the carry.
			 */
			*tmpc   = *tmpa++ + b;
			mu      = *tmpc >> DIGIT_BIT;
			*tmpc++ &= MP_MASK;

			/* now handle rest of the digits */
			for (ix = 1; ix < a->used; ix++) {
				*tmpc   = *tmpa++ + mu;
				mu      = *tmpc >> DIGIT_BIT;
				*tmpc++ &= MP_MASK;
			}
			/* set final carry */
			ix++;
			*tmpc++  = mu;
			
			/* setup size */
			c->used = a->used + 1;
		} else {
			/* a was negative and |a| < b */
			c->used  = 1;
			
			/* the result is a single digit */
			if (a->used == 1) {
				*tmpc++  =  b - a->dp[0];
			} else {
				*tmpc++  =  b;
			}
			
			/* setup count so the clearing of oldused
			 * can fall through correctly
			 */
			ix       = 1;
		}

		/* now zero to oldused */
		while (ix++ < oldused) {
			*tmpc++ = 0;
		}
		nm_clamp();
		
		return MP_OKAY;
	}

	int nint::nm_add_d(nm_digit v) {
		return nm_add_d(v, *this);
	}
}
