#ifndef TIMEVAL_H_
#define TIMEVAL_H_


#include <stdlib.h>

struct Timeval
{
	time_t tv_sec;
	suseconds_t tv_usec;
};

#endif /* TIMEVAL_H_ */