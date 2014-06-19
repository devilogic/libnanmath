#include "nanmath.h"

namespace nanan {
	int nint::nm_grow(unsigned size) {
		unsigned i = 0;
		nm_digit* tmp = NULL;

		/* 如果已经分配的内存小于指定的 */
		if (_data.alloc_size < size) {
			size += (NM_PREC * 2) - (size % NM_PREC);
			
			/* 重新分配内存 */
			tmp = (nm_digit*)realloc_memory(_data.bits, 
											sizeof(nm_digit) * size);
			if (tmp == NULL) {
				_errno = NM_ERROR_MEM;
				return NM_SUCCESS;
			}
			
			_data.bits = tmp;
			
			/* 清零 */
			i = _data.alloc_size;
			_data.alloc_size = size;
			for (; i < _data.alloc_size; i++) {
				_data.bits[i] = 0;
			}
		}
		return NM_SUCCESS;
	}
}
