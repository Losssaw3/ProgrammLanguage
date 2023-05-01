#include "Date.h"

double FromUnixToJ2000()
{
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	return (end_time / 86400.0) + 2440587.5 - 2451545;
}