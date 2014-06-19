#include "nanmath.h"

namespace nanan {
    int nint::nm_read_unsigned_bin(const unsigned char* v UNUSED, 
								   unsigned size UNUSED) {
//         unsigned res = 0;

//         /* 确认最少有两位 */ 
//         if (_data.alloc_size < 2) {
//             if ((res = nm_grow(2)) != NM_SUCCESS) {
//                 return res;
//             }
//         }

//         /* 清0 */
//         nm_zero();

//         /* 读取字节 */
//         while (size-- > 0) {
//             if ((res = mp_mul_2d (&_data, 8, &_data)) != NM_SUCCESS) {
//                 return res;
//             }

// #if NM_DIGIT == 8
// 			_data.bits[0] = (*b & NM_MASK);
// 			_data.bits[1] |= ((*b++ >> 7U) & 1);
// 			_data.bits_counts += 2;
// #else
// 			_data.bits[0] |= *b++;
// 			_data.bits_counts += 1;
// #endif
// 		}
		
//         nm_clamp();
        return NM_SUCCESS;
    }
}
