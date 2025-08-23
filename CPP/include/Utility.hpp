#pragma once

#include <iostream>
#include <chrono>
#include <sstream>
#include <vector>

class Utility
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

    template<typename T>
    void printVecWithDelim(const std::vector<T>& vec, const char ch1, const char ch2) {
        std::cout << ch1;
        for (auto i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ',';
            }
        }
        std::cout << ch2 << '\n';        
    }
};