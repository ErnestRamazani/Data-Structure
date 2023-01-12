#ifndef TIMEINTERVAL_H_EXISTS
#define TIMEINTERVAL_H_EXISTS


/*struct timeval{
long    tv_sec;         // seconds
long    tv_usec;        // microseconds
};
*/


class TimeInterval {
public:
	timeval start_time;
	timeval end_time;
public:
	TimeInterval();
	void start();
	void stop();
	float GetInterval();
};

#endif; 