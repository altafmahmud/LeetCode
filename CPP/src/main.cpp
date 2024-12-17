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

    std::cout << "\n"
              << std::boolalpha;
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

    std::cout << '\n';
    FindFirstLastPosOfElemInSortedArray fflpoesa;
    int_vec1 = {5, 7, 7, 8, 8, 10};
    int_vec2 = fflpoesa.searchRange(int_vec1, 8);
    std::cout << '[' << int_vec2[0] << ',' << int_vec2[1] << ']' << '\n';
    int_vec1 = {5, 7, 7, 8, 8, 10};
    int_vec2 = fflpoesa.searchRange(int_vec1, 6);
    std::cout << '[' << int_vec2[0] << ',' << int_vec2[1] << ']' << '\n';
    int_vec1 = {};
    int_vec2 = fflpoesa.searchRange(int_vec1, 0);
    std::cout << '[' << int_vec2[0] << ',' << int_vec2[1] << ']' << '\n';
    int_vec1 = {1};
    int_vec2 = fflpoesa.searchRange(int_vec1, 1);
    std::cout << '[' << int_vec2[0] << ',' << int_vec2[1] << ']' << '\n';
    int_vec1 = {1, 3};
    int_vec2 = fflpoesa.searchRange(int_vec1, 1);
    std::cout << '[' << int_vec2[0] << ',' << int_vec2[1] << ']' << '\n';
    int_vec1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
    int_vec2 = fflpoesa.searchRange(int_vec1, 1);
    std::cout << '[' << int_vec2[0] << ',' << int_vec2[1] << ']' << '\n';
    int_vec2 = fflpoesa.searchRange(int_vec1, 2);
    std::cout << '[' << int_vec2[0] << ',' << int_vec2[1] << ']' << '\n';
    int_vec1 = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    int_vec2 = fflpoesa.searchRange(int_vec1, 5);
    std::cout << '[' << int_vec2[0] << ',' << int_vec2[1] << ']' << '\n';

    std::cout << '\n';
    PlatesBetweenCandles pbc;
    std::string tableTop("**|**|***|");
    std::vector<std::vector<int>> queries = {{2, 5}, {5, 9}};
    auto plates = pbc.platesBetweenCandles(tableTop, queries);
    std::copy(plates.begin(), plates.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << '\n';
    tableTop = "||**||**|*";
    queries = {{3, 18}};
    plates = pbc.platesBetweenCandles(tableTop, queries);
    std::copy(plates.begin(), plates.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << '\n';
    tableTop = "***|**|*****|**||**|*";
    queries = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
    plates = pbc.platesBetweenCandles(tableTop, queries);
    std::copy(plates.begin(), plates.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << '\n';
    tableTop = "**|*******************|**********************************************|************|*********|*****| \
                *********************************************************************************************|***";
    queries = {{31, 96}, {14, 192}, {0, 180}, {13, 193}, {12, 192}, {11, 183}, {12, 189}, {65, 116}, {55, 160}, {100, 164}, {6, 183}, {4, 182}, {15, 183}, {0, 194}, {37, 63}, {10, 184}, {0, 183}, {5, 184}, {8, 185}, {13, 136}, {6, 192}, {5, 189}, {13, 183}, {8, 184}, {15, 188}, {0, 184}, {9, 191}, {4, 193}, {61, 83}, {1, 193}, {10, 194}, {15, 192}, {13, 184}, {2, 185}, {11, 190}, {11, 195}, {14, 188}, {12, 188}, {94, 116}, {3, 184}, {0, 189}, {4, 185}, {12, 193}, {3, 185}, {1, 181}, {6, 194}, {0, 185}, {10, 193}, {5, 187}, {10, 185}, {12, 182}, {23, 80}, {10, 191}, {10, 195}, {13, 189}, {6, 193}, {5, 183}, {2, 182}, {14, 181}, {3, 187}, {9, 187}, {4, 180}, {5, 190}, {4, 181}, {7, 184}, {3, 135}, {6, 189}, {14, 186}, {5, 195}, {11, 186}, {8, 186}, {30, 159}, {11, 192}, {61, 80}, {3, 181}, {5, 192}, {10, 187}, {2, 25}, {9, 194}, {43, 118}, {2, 189}, {8, 180}, {15, 193}, {13, 181}, {14, 182}, {105, 133}, {8, 195}, {0, 193}, {13, 192}, {3, 186}, {1, 189}, {24, 124}, {0, 181}, {136, 158}, {11, 193}, {14, 180}, {11, 180}, {54, 149}, {8, 191}, {11, 188}, {4, 188}, {2, 181}, {5, 188}, {11, 181}, {43, 175}, {12, 183}, {0, 186}, {6, 188}, {0, 191}, {15, 186}, {8, 187}, {7, 74}, {3, 180}, {27, 149}, {73, 153}, {52, 145}, {9, 188}, {7, 195}, {14, 193}, {77, 160}, {0, 187}, {10, 188}, {4, 187}, {62, 160}, {13, 190}, {12, 190}, {5, 191}, {14, 184}, {9, 186}, {7, 189}, {131, 148}, {9, 189}, {159, 179}, {20, 174}, {13, 180}, {4, 184}, {0, 192}, {2, 190}, {0, 195}, {10, 180}, {9, 182}, {9, 181}, {11, 194}, {12, 194}, {5, 185}, {3, 189}, {118, 160}, {5, 181}, {14, 122}, {25, 63}, {11, 189}, {3, 193}, {31, 176}, {58, 148}, {9, 183}, {11, 184}, {35, 181}, {12, 186}, {14, 190}, {8, 190}, {15, 194}, {1, 195}, {4, 194}, {2, 180}, {9, 190}, {3, 182}, {15, 181}, {13, 194}, {6, 182}, {42, 117}, {4, 186}, {13, 187}, {25, 103}, {6, 184}, {5, 180}, {21, 180}, {1, 187}, {15, 189}, {6, 180}, {44, 160}, {8, 182}, {15, 180}, {10, 182}, {1, 180}, {7, 185}, {8, 193}};
    queries = {{100, 164}};
    plates = pbc.platesBetweenCandles(tableTop, queries);
    std::copy(plates.begin(), plates.end(), std::ostream_iterator<int>(std::cout, ","));

    std::cout << "\n\n" << std::boolalpha;
    CanMakePaliFrmSubstr can_pali;
    std::string s("abcda");
    queries = {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
    auto bool_vec = can_pali.canMakePaliQueries(s, queries);
    for (const auto b : bool_vec)
    {
        std::cout << b << ',';
    }
    std::cout << '\n';
    s = ("lyb");
    queries = {{0, 1, 0}, {2, 2, 0}};
    bool_vec = can_pali.canMakePaliQueries(s, queries);
    for (const auto b : bool_vec)
    {
        std::cout << b << ',';
    }
    std::cout << std::noboolalpha << '\n';
    return 0;
}
