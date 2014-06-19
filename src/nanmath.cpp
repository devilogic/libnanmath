#include "nanmath.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

namespace nanan {
	nint::nint() {
		memset(&_data, 0, sizeof(_data));
		_errno = NM_ERROR_OK;
		strcpy(_nm_s_rmap,
			   "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/");

		init();
	}

	nint::~nint() {
		if (_data.bits) free(_data.bits);
	}

	unsigned nint::get_bits_counts() {
		return _data.bits_counts;
	}

	unsigned nint::get_alloc_size() {
		return _data.alloc_size;
	}

	unsigned nint::get_sign() {
		return _data.sign;
	}

	void nint::set_bits_counts(unsigned bits_counts) {
		_data.bits_counts = bits_counts;
	}

	void nint::set_alloc_size(unsigned alloc_size) {
		_data.alloc_size = alloc_size;
	}

	void nint::set_sign(unsigned sign) {
		if ((sign != NM_ZPOS) && (sign != NM_NEG))
			sign = NM_ZPOS;
		_data.sign = sign;
	}

	void nint::read(void* v) {
		assert(v);
		memcpy(&_data, v, sizeof(_data));
	}

	void nint::write(void* v) {
		assert(v);
		memcpy(v, &_data, sizeof(_data));
	}

	int nint::get_last_error() {
		return _errno;
	}

	int nint::init() {
		int i;
		
		size_t size = sizeof(nm_digit) * NM_PREC;
		_data.bits = (nm_digit*)malloc_memory(size);
		if (_data.bits == NULL) {
			_errno = NM_ERROR_MEM;
			return NM_ERROR;
		}
		
		for (i = 0; i < NM_PREC; i++) {
			_data.bits[i] = 0;
		}

		_data.alloc_size = size;
		_data.bits_counts = 0;
		_data.sign = NM_ZPOS;

		return NM_SUCCESS;
	}

	void* nint::malloc_memory(size_t size) {
		return malloc(size);
	}

	void* nint::realloc_memory(void* ptr, size_t size) {
		return realloc(ptr, size);
	}

	void* nint::calloc_memory(size_t nmemb, size_t size) {
		return calloc(nmemb, size);
	}

	void nint::free_memory(void* ptr) {
		free(ptr);
	}
}

