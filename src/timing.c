/****************************************************************************
 * Timing functions.
 * Copyright (C) 2004 Joe Wingbermuehle
 ****************************************************************************/

#include "jwm.h"

static const unsigned long MAX_TIME_SECONDS = 60;

/****************************************************************************
 ****************************************************************************/
void InitializeTiming() {
}

/****************************************************************************
 ****************************************************************************/
void StartupTiming() {
}

/****************************************************************************
 ****************************************************************************/
void ShutdownTiming() {
}

/****************************************************************************
 ****************************************************************************/
void DestroyTiming() {
}

/****************************************************************************
 * Get the current time in milliseconds since midnight 1970-01-01 UTC.
 ****************************************************************************/
void GetCurrentTime(TimeType *t) {
	struct timeval val;
	gettimeofday(&val, NULL);
	t->seconds = val.tv_sec;
	t->ms = val.tv_usec / 1000;
}

/****************************************************************************
 * Get the absolute difference between two times in milliseconds.
 * If the difference is larger than a MAX_TIME_SECONDS, then
 * MAX_TIME_SECONDS will be returned.
 * Note that the times must be normalized.
 ****************************************************************************/
unsigned long GetTimeDifference(const TimeType *t1, const TimeType *t2) {
	unsigned long deltaSeconds;
	int deltaMs;

	if(t1->seconds > t2->seconds) {
		deltaSeconds = t1->seconds - t2->seconds;
		deltaMs = t1->ms - t2->ms;
	} else if(t1->seconds < t2->seconds) {
		deltaSeconds = t2->seconds - t1->seconds;
		deltaMs = t2->ms - t1->ms;
	} else if(t1->ms > t2->ms) {
		deltaSeconds = 0;
		deltaMs = t1->ms - t2->ms;
	} else {
		deltaSeconds = 0;
		deltaMs = t2->ms - t1->ms;
	}

	if(deltaSeconds > MAX_TIME_SECONDS) {
		return MAX_TIME_SECONDS * 1000;
	} else {
		return deltaSeconds * 1000 + deltaMs;
	}

}


