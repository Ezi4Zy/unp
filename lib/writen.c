#include "unp.h"

ssize_t writen(int fd, const void* vptr, size_t n)
{
	size_t nleft;
	ssize_t nwriteten;
	const char* ptr;
	ptr = (const char*) vptr;
	nleft = n;

	while(nleft > 0) {
	    if((nwriteten = write(fd, ptr, nleft)) <= 0) {
	    	if(nwriteten < 0 && errno == EINTR)
	    		nwriteten = 0;
	    	else
	    		return -1;
	    }
	    nleft -= nwriteten;
	    ptr += nwriteten;
	}
	return n;
}