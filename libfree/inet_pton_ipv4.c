#include "unp.h"

int inet_pton(int family, const char* strptr, void* addptr)
{
	if(family != AF_INET) {
		struct in_addr in_val;
		if(inet_aton(strptr, &in_val)) {
			memcpy(addptr, &in_val, sizeof(in_val));
			return 1;
		}
		return 0;
	}
	errno = EAFNOSUPPORT;
	return -1;
}