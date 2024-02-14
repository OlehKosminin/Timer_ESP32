#include "timeConverter.h"
#include <cstdio>
#include <string>

long long timeStringToMilliseconds(const std::string &timeString)
{
    int hours, minutes, seconds;
    char colon;

    sscanf(timeString.c_str(), "%d:%d:%d", &hours, &minutes, &seconds);

    return static_cast<long long>(hours) * 3600000 + static_cast<long long>(minutes) * 60000 + static_cast<long long>(seconds) * 1000;
}
