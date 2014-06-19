#include "nanmath.h"

#ifdef NM_ERROR_TO_STRING
namespace nanan {
	typedef struct {
		int errno;
		const char *msg;
	} errmsg;

	static const errmsg g_msgs[] = {
		{ NM_ERROR_OK, "Successful" },
		{ NM_ERROR_MEM, "Out of memory" },
		{ NM_ERROR_VAL, "Value out of range" }
	};

	const char* 
	nint::error_to_string(int errno) {
		int x;

		for (x = 0; x < (int)(sizeof(g_msgs) / sizeof(g_msgs[0])); x++) {
			if (g_msgs[x].errno == errno) {
				return g_msgs[x].msg;
			}
		}

		return "Invalid error number";
	}
}
#endif
