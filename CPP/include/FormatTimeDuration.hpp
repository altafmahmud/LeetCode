#pragma once

#include <chrono>
#include <sstream>

class Helper
{
public:
    std::string formatMsToString(std::chrono::milliseconds ms)
    {
        using namespace std::chrono;
        auto secs = duration_cast<seconds>(ms);
        ms -= duration_cast<milliseconds>(secs);
        auto mins = duration_cast<minutes>(secs);
        secs -= duration_cast<seconds>(mins);
        auto hour = duration_cast<hours>(mins);
        mins -= duration_cast<minutes>(hour);

        std::ostringstream oss;
        oss << hour.count() << " Hours : " << mins.count() << " Minutes : " << secs.count() << " Seconds : " << ms.count() << " Milliseconds";
        return oss.str();
    }
};