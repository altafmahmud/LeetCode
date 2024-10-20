#include "Solutions.hpp"

int main()
{
    MedianTwoSortedArrays med;
    std::vector<int> int_vec1 = {10, 20, 30, 40, 50};
    std::vector<int> int_vec2 = {5, 15, 25, 35, 45};
    const auto median = med.findMedianSortedArrays(int_vec1, int_vec2);
    std::cout << "Median: " << median << '\n';

    LongestCommonPrefix lcp;
    std::vector<std::string> str_vec = {"aabbbc", "aabdc", "aabbbd"};
    std::cout << "LCP: " << lcp.longestCommonPrefix(str_vec) << '\n';

    LengthOfLCP lenOfLCP;
    int_vec1.clear();
    int_vec2.clear();
    int_vec1 = {1, 10, 100, 1000, 99999};
    int_vec2 = {1000, 10000, 999999};
    std::cout << "Length of LCP: " << lenOfLCP.longestCommonPrefix(int_vec1, int_vec2) << '\n';

    LongestHappyString happy;
    std::cout << "Happy string: " << happy.longestDiverseString(0, 0, 7) << '\n';

    MinLengthAfterRemoveSubstr minLength;
    std::cout << "Minimum length: " << minLength.minLength("ABFCACDB") << '\n';
    return 0;
}
