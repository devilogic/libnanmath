#ifndef __LIBNANMATH_NANMATH_H__
#define __LIBNANMATH_NANMATH_H__

#include "nm_config.h"

namespace nanan {

#ifndef MIN
   #define MIN(x,y) ((x)<(y)?(x):(y))
#endif

#ifndef MAX
   #define MAX(x,y) ((x)>(y)?(x):(y))
#endif

	/* 比较符号 */
	enum {
		NM_LT = -1,
		NM_EQ = 0,
		NM_GT = 1
	};

	/* 正负号 */
	enum {
		NM_ZPOS = 0,
		NM_NEG = 1
	};

	/* 错误代码 */
	enum {
		NM_ERROR_OK = 0,
		NM_ERROR_MEM = -2,
		NM_ERROR_VAL = -3,
		NM_ERROR_RANGE = -3
	};

	/* 返回值 */
	enum {
		NM_SUCCESS = 0,
		NM_ERROR = 1
	};

#define USED(x)    ((x)->get_bits_counts())
#define DIGIT(x, b) (*((nm_digit*)(x) + b))
#define SIGN(x)    ((x)->get_sign)

	typedef struct _nint_data {
		unsigned bits_counts;
		unsigned alloc_size;
		unsigned sign;
		nm_digit* bits;
	} nint_data;

	class nint {
	public:
		nint();
		virtual ~nint();

	public:
		unsigned get_bits_counts();
		unsigned get_alloc_size();
		unsigned get_sign();
		
		void set_bits_counts(unsigned bits_counts);
		void set_alloc_size(unsigned alloc_size);
		void set_sign(unsigned sign);

		void read(void* v);
		void write(void* v);

		int get_last_error();

	protected:
		int init();

	protected:
		virtual void* malloc_memory(size_t size);
		virtual void* realloc_memory(void* ptr, size_t size);
		virtual void* calloc_memory(size_t nmemb, size_t size);
		virtual void free_memory(void* ptr);

	public:
		int nm_iszero();
		int nm_iseven();
		int nm_isodd();

		void nm_zero();
		int nm_grow(unsigned size);
		void nm_clamp();
		
		int nm_read_unsigned_bin(const unsigned char* v, unsigned size);
		int nm_read_radix(const char* str, int radix);

		int nm_add_d(nm_digit v, nint& result);
		int nm_add_d(nm_digit v);
		int nm_sub_d(nm_digit v, nint& result);
		int nm_sub_d(nm_digit v);
		int nm_mul_d(nm_digit v, nint& result);
		int nm_mul_d(nm_digit v);


#ifdef NM_OP_PTR
		operator nm_digit ();
		operator nint_data ();

		operator nm_digit* ();
		operator nint_data* ();
#endif

#ifdef NM_OP_EQ
		nint& operator= (nint& v);
		nint& operator= (char v);
		nint& operator= (short v);
		nint& operator= (int v);
		nint& operator= (long v);
		nint& operator= (unsigned char v);
		nint& operator= (unsigned short v);
		nint& operator= (unsigned int v);
		nint& operator= (unsigned long v);
		nint& operator= (char* v);
#endif

		/* nint& operator+ (nint& v); */
		/* nint& operator- (nint& v); */
		/* nint& operator* (nint& v); */
		/* nint& operator/ (nint& v); */
		/* nint& operator% (nint& v); */
		/* nint& operator^ (nint& v); */
		/* nint& operator~ (nint& v); */

#ifdef NM_ERROR_TO_STRING
		static const char* error_to_string(int errno);
#endif

	protected:
		nint_data _data;
		int _errno;

	private:
		char _nm_s_rmap[128];
    };
}

#endif
