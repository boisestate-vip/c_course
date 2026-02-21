
#include "sleep.h"

#ifdef __unix__
#include <unistd.h>

void sleep_s(double s) {
   int time_us = (int)(s * 1000000.0);
   usleep(time_us);
}

#elif defined( _WIN32 ) // windows
#include <windows.h>

void sleep_s(double s) {
   int time_ms = (int)(s * 1000.0);
   Sleep(time_ms);
}

#else
#error unsupported os!
#endif
