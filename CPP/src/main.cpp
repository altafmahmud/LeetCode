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

    RankArrayTransform rankArrayTransform;
    int_vec1 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    int_vec2 = rankArrayTransform.arrayRankTransform(int_vec1);
    std::cout << "Array rank: ";
    std::copy(int_vec2.begin(), int_vec2.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << '\n';

    UncommonWords uncommonWords;
    std::cout << "Uncommon words: ";
    auto strVec = uncommonWords.uncommonFromSentences("fo ly ly", "fo fo etx");
    std::copy(strVec.begin(), strVec.end(), std::ostream_iterator<std::string>(std::cout, ","));
    std::cout << '\n';

    EqualSubstrInBudget equalSubstrInBudget;
    std::cout << "Length of equal substrings in budget: " << equalSubstrInBudget.equalSubstring("pxezla", "loewbi", 25) << '\n'; // 4
    std::cout << "Length of equal substrings in budget: " << equalSubstrInBudget.equalSubstring("abcd", "acde", 0) << '\n';      // 1
    std::cout << "Length of equal substrings in budget: " << equalSubstrInBudget.equalSubstring("abcd", "cdef", 1) << '\n';      // 0
    std::cout << "Length of equal substrings in budget: " << equalSubstrInBudget.equalSubstring("abcd", "bcdf", 3) << '\n';      // 3

    RemDupSortedArr rem;
    int_vec1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    auto k = rem.removeDuplicates(int_vec1);
    std::cout << "K: " << k << '\n';
    std::copy(int_vec1.begin(), int_vec1.end(), std::ostream_iterator<int>(std::cout, ","));

    std::cout << "\n\n";
    RemElement rmElm;
    int_vec1 = {0, 1, 2, 2, 3, 0, 4, 2};
    k = rmElm.removeElement(int_vec1, 2);
    std::copy(int_vec1.begin(), int_vec1.begin() + k, std::ostream_iterator<int>(std::cout, ","));
    std::cout << "\n";
    int_vec1 = {3, 2, 2, 3};
    k = rmElm.removeElement(int_vec1, 3);
    std::copy(int_vec1.begin(), int_vec1.begin() + k, std::ostream_iterator<int>(std::cout, ","));

    std::cout << "\n\n";
    DivideTwoInt divTwoInt;
    std::cout << divTwoInt.divide(10, 3) << '\n';
    std::cout << divTwoInt.divide(-2147483648, 2) << '\n';
    std::cout << divTwoInt.divide(2147483647, -1) << '\n';
    std::cout << divTwoInt.divide(-2147483648, -2147483648) << '\n';
    std::cout << divTwoInt.divide(-2147483648, 2147483647) << '\n';

    std::cout << "\n";
    SearchInRotatedSortedArr search;
    int_vec1 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << search.search(int_vec1, 0) << '\n';
    std::cout << search.search(int_vec1, 3) << '\n';
    int_vec1 = {1};
    std::cout << search.search(int_vec1, 3) << '\n';
    int_vec1 = {1, 3};
    std::cout << search.search(int_vec1, 0) << '\n';
    int_vec1 = {4, 5, 1, 2, 3};
    std::cout << search.search(int_vec1, 1) << '\n';

    std::cout << "\n" << std::boolalpha;
    SearchInRotatedSortedArrII searchII;
    int_vec1 = {4, 5, 6, 6, 7, 0, 1, 2, 4, 4};
    std::cout << searchII.search(int_vec1, 6) << '\n'; // true
    std::cout << searchII.search(int_vec1, 4) << '\n'; // true
    std::cout << searchII.search(int_vec1, 2) << '\n'; // true
    std::cout << searchII.search(int_vec1, 3) << '\n'; // false
    int_vec1 = {2, 5, 6, 0, 0, 1, 2};
    std::cout << searchII.search(int_vec1, 0) << '\n'; // true
    int_vec1 = {2, 5, 6, 0, 0, 1, 2};
    std::cout << searchII.search(int_vec1, 3) << '\n'; // false
    int_vec1 = {1};
    std::cout << searchII.search(int_vec1, 3) << '\n'; // false
    int_vec1 = {1, 3};
    std::cout << searchII.search(int_vec1, 3) << '\n'; // true
    int_vec1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    std::cout << searchII.search(int_vec1, 2) << '\n'; // true
    std::cout << std::noboolalpha;

    return 0;
}
