#include "AllSolutionHeaders.hpp"

int main()
{
    {
        std::cout << "Solution 4:\n";
        MedianTwoSortedArrays med;
        std::vector<int> int_vec1 = {10, 20, 30, 40, 50};
        std::vector<int> int_vec2 = {5, 15, 25, 35, 45};
        const auto median = med.findMedianSortedArrays(int_vec1, int_vec2);
        std::cout << "Median: " << median << "\n\n";
    }

    {
        std::cout << "Solution 14:\n";
        LongestCommonPrefix lcp;
        std::vector<std::string> str_vec = {"aabbbc", "aabdc", "aabbbd"};
        std::cout << "LCP: " << lcp.longestCommonPrefix(str_vec) << "\n\n";
    }

    {
        std::cout << "Solution 3043:\n";
        LengthOfLCP lenOfLCP;
        std::vector<int> int_vec1 = {1, 10, 100, 1000, 99999};
        std::vector<int> int_vec2 = {1000, 10000, 999999};
        std::cout << "Length of LCP: " << lenOfLCP.longestCommonPrefix(int_vec1, int_vec2) << "\n\n";
    }

    {
        std::cout << "Solution 1405:\n";
        LongestHappyString happy;
        std::cout << "Happy string: " << happy.longestDiverseString(0, 0, 7) << "\n\n";
    }

    {
        std::cout << "Solution 2696:\n";
        MinLengthAfterRemoveSubstr minLength;
        std::cout << "Minimum length: " << minLength.minLength("ABFCACDB") << "\n\n";
    }

    {
        std::cout << "Solution 1331:\n";
        RankArrayTransform rankArrayTransform;
        std::vector<int> int_vec = {37, 12, 28, 9, 100, 56, 80, 5, 12};
        auto res_vec = rankArrayTransform.arrayRankTransform(int_vec);
        std::cout << "Array rank: ";
        std::copy(res_vec.begin(), res_vec.end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << "\n\n";
    }

    {
        std::cout << "Solution 884:\n";
        UncommonWords uncommonWords;
        std::cout << "Uncommon words: ";
        auto strVec = uncommonWords.uncommonFromSentences("fo ly ly", "fo fo etx");
        std::copy(strVec.begin(), strVec.end(), std::ostream_iterator<std::string>(std::cout, ","));
        std::cout << "\n\n";
    }

    {
        std::cout << "Solution 1208:\n";
        EqualSubstrInBudget equalSubstrInBudget;
        std::cout << "Length of equal substrings in budget: " << equalSubstrInBudget.equalSubstring("pxezla", "loewbi", 25) << '\n'; // 4
        std::cout << "Length of equal substrings in budget: " << equalSubstrInBudget.equalSubstring("abcd", "acde", 0) << '\n';      // 1
        std::cout << "Length of equal substrings in budget: " << equalSubstrInBudget.equalSubstring("abcd", "cdef", 1) << '\n';      // 0
        std::cout << "Length of equal substrings in budget: " << equalSubstrInBudget.equalSubstring("abcd", "bcdf", 3) << "\n\n";    // 3
    }

    {
        std::cout << "Solution 26:\n";
        RemDupSortedArr rem;
        std::vector<int> int_vec = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        auto k = rem.removeDuplicates(int_vec);
        std::cout << "K: " << k << '\n';
        std::copy(int_vec.begin(), int_vec.end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << "\n\n";
    }

    {
        std::cout << "Solution 27:\n";
        RemElement rmElm;
        std::vector<int> int_vec = {0, 1, 2, 2, 3, 0, 4, 2};
        auto k = rmElm.removeElement(int_vec, 2);
        std::copy(int_vec.begin(), int_vec.begin() + k, std::ostream_iterator<int>(std::cout, ","));
        std::cout << "\n";
        int_vec = {3, 2, 2, 3};
        k = rmElm.removeElement(int_vec, 3);
        std::copy(int_vec.begin(), int_vec.begin() + k, std::ostream_iterator<int>(std::cout, ","));
        std::cout << "\n\n";
    }

    {
        std::cout << "Solution 29\n";
        DivideTwoInt divTwoInt;
        std::cout << divTwoInt.divide(10, 3) << '\n';
        std::cout << divTwoInt.divide(-2147483648, 2) << '\n';
        std::cout << divTwoInt.divide(2147483647, -1) << '\n';
        std::cout << divTwoInt.divide(-2147483648, -2147483648) << '\n';
        std::cout << divTwoInt.divide(-2147483648, 2147483647) << "\n\n";
    }

    {
        std::cout << "Solution 33\n";
        SearchInRotatedSortedArr search;
        std::vector<int> int_vec = {4, 5, 6, 7, 0, 1, 2};
        std::cout << search.search(int_vec, 0) << '\n';
        std::cout << search.search(int_vec, 3) << '\n';
        int_vec = {1};
        std::cout << search.search(int_vec, 3) << '\n';
        int_vec = {1, 3};
        std::cout << search.search(int_vec, 0) << '\n';
        int_vec = {4, 5, 1, 2, 3};
        std::cout << search.search(int_vec, 1) << "\n\n";
    }

    {
        std::cout << "Solution 81:\n"
                  << std::boolalpha;
        SearchInRotatedSortedArrII searchII;
        std::vector<int> int_vec = {4, 5, 6, 6, 7, 0, 1, 2, 4, 4};
        std::cout << searchII.search(int_vec, 6) << '\n'; // true
        std::cout << searchII.search(int_vec, 4) << '\n'; // true
        std::cout << searchII.search(int_vec, 2) << '\n'; // true
        std::cout << searchII.search(int_vec, 3) << '\n'; // false
        int_vec = {2, 5, 6, 0, 0, 1, 2};
        std::cout << searchII.search(int_vec, 0) << '\n'; // true
        int_vec = {2, 5, 6, 0, 0, 1, 2};
        std::cout << searchII.search(int_vec, 3) << '\n'; // false
        int_vec = {1};
        std::cout << searchII.search(int_vec, 3) << '\n'; // false
        int_vec = {1, 3};
        std::cout << searchII.search(int_vec, 3) << '\n'; // true
        int_vec = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
        std::cout << searchII.search(int_vec, 2) << "\n\n"; // true
        std::cout << std::noboolalpha;
    }

    {
        std::cout << "Solution 34:\n";
        FindFirstLastPosOfElemInSortedArray fflpoesa;
        std::vector<int> int_vec = {5, 7, 7, 8, 8, 10};
        auto res_vec = fflpoesa.searchRange(int_vec, 8);
        std::cout << '[' << res_vec[0] << ',' << res_vec[1] << ']' << '\n';
        int_vec = {5, 7, 7, 8, 8, 10};
        res_vec = fflpoesa.searchRange(int_vec, 6);
        std::cout << '[' << res_vec[0] << ',' << res_vec[1] << ']' << '\n';
        int_vec = {};
        res_vec = fflpoesa.searchRange(int_vec, 0);
        std::cout << '[' << res_vec[0] << ',' << res_vec[1] << ']' << '\n';
        int_vec = {1};
        res_vec = fflpoesa.searchRange(int_vec, 1);
        std::cout << '[' << res_vec[0] << ',' << res_vec[1] << ']' << '\n';
        int_vec = {1, 3};
        res_vec = fflpoesa.searchRange(int_vec, 1);
        std::cout << '[' << res_vec[0] << ',' << res_vec[1] << ']' << '\n';
        int_vec = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
        res_vec = fflpoesa.searchRange(int_vec, 1);
        std::cout << '[' << res_vec[0] << ',' << res_vec[1] << ']' << '\n';
        res_vec = fflpoesa.searchRange(int_vec, 2);
        std::cout << '[' << res_vec[0] << ',' << res_vec[1] << ']' << '\n';
        int_vec = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
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
        res_vec = fflpoesa.searchRange(int_vec, 5);
        std::cout << '[' << res_vec[0] << ',' << res_vec[1] << ']' << "\n\n";
    }

    {
        std::cout << "Solution 2055:\n";
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
        std::cout << "\n\n";
    }

    {
        std::cout << "Solution 1177:\n"
                  << std::boolalpha;
        CanMakePaliFrmSubstr can_pali;
        std::string s("abcda");
        std::vector<std::vector<int>> queries = {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
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
        std::cout << std::noboolalpha << "\n\n";
    }

    {
        std::cout << "Solution 3000:\n";
        MaxAreaLongestDiagonalRectangle maldr;
        std::vector<std::vector<int>> dims = {{9, 3}, {8, 6}};
        std::cout << maldr.areaOfMaxDiagonal(dims) << '\n';
        dims = {{3, 4}, {4, 3}};
        std::cout << maldr.areaOfMaxDiagonal(dims) << '\n';
        dims = {{10, 3}, {5, 9}, {8, 3}};
        std::cout << maldr.areaOfMaxDiagonal(dims) << "\n\n";
    }

    {
        std::cout << "Solution 515:\n";
        LargestValueInEachRowBTree largestValEachRow;
        std::vector<std::string> str_vec = {"1", "3", "2", "5", "3", "null", "9"};
        auto root = largestValEachRow.buildTree(str_vec);
        auto max_vec = largestValEachRow.largestValues(root);
        std::copy(max_vec.begin(), max_vec.end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << '\n';
        str_vec = {"1", "2", "3"};
        root = largestValEachRow.buildTree(str_vec);
        max_vec = largestValEachRow.largestValues(root);
        std::copy(max_vec.begin(), max_vec.end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << "\n\n";
    }

    {
        std::cout << "Solution 167:\n";
        TwoSumII twoSum2;
        std::vector<int> int_vec = {2, 7, 11, 15};
        auto target = 9;
        auto output = twoSum2.twoSum(int_vec, target);
        std::copy(output.begin(), output.end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << "\n\n";
    }

    {
        std::cout << "Solution 15:\n";
        ThreeSum threeSum;
        std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
        auto res_vec = threeSum.threeSum(nums);
        for (const auto &v : res_vec)
        {
            std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
            std::cout << '\n';
        }
        nums = {0, 1, 1};
        res_vec = threeSum.threeSum(nums);
        for (const auto &v : res_vec)
        {
            std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
            std::cout << '\n';
        }
        std::cout << '\n';
        nums = {0, 0, 0, 0, 0, 0, 0, 0};
        res_vec = threeSum.threeSum(nums);
        for (const auto &v : res_vec)
        {
            std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
            std::cout << '\n';
        }
        std::cout << '\n';
        nums = {-2, 0, 1, 1, 2};
        res_vec = threeSum.threeSum(nums);
        for (const auto &v : res_vec)
        {
            std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    {
        std::cout << "Solution 2:\n";
        AddTwoNum addTowSum;
        std::vector<int> int_vec1 = {2, 4, 3};
        auto list1 = addTowSum.buildList(int_vec1);
        std::cout << "List 1:\n";
        addTowSum.printList(list1);
        std::cout << '\n';
        std::vector<int> int_vec2 = {5, 6, 4};
        auto list2 = addTowSum.buildList(int_vec2);
        std::cout << "List 2:\n";
        addTowSum.printList(list2);
        std::cout << '\n';
        auto res_list = addTowSum.addTwoNumbers(list1, list2);
        std::cout << "Result list:\n";
        addTowSum.printList(res_list);
        std::cout << '\n';
        addTowSum.clearList(list1);
        addTowSum.clearList(list2);
        addTowSum.clearList(res_list);

        int_vec1 = {9, 9, 9, 9, 9, 9, 9};
        list1 = addTowSum.buildList(int_vec1);
        std::cout << "List 1:\n";
        addTowSum.printList(list1);
        std::cout << '\n';
        int_vec2 = {9, 9, 9, 9};
        list2 = addTowSum.buildList(int_vec2);
        std::cout << "List 2:\n";
        addTowSum.printList(list2);
        std::cout << '\n';
        res_list = addTowSum.addTwoNumbers(list1, list2);
        std::cout << "Result list:\n";
        addTowSum.printList(res_list);
        std::cout << '\n';
        addTowSum.clearList(list1);
        addTowSum.clearList(list2);
        addTowSum.clearList(res_list);

        int_vec1 = {0};
        list1 = addTowSum.buildList(int_vec1);
        std::cout << "List 1:\n";
        addTowSum.printList(list1);
        std::cout << '\n';
        int_vec2 = {0};
        list2 = addTowSum.buildList(int_vec2);
        std::cout << "List 2:\n";
        addTowSum.printList(list2);
        std::cout << '\n';
        res_list = addTowSum.addTwoNumbers(list1, list2);
        std::cout << "Result list:\n";
        addTowSum.printList(res_list);
        std::cout << '\n';
        addTowSum.clearList(list1);
        addTowSum.clearList(list2);
        addTowSum.clearList(res_list);
        std::cout << '\n';
    }

    {
        std::cout << "Solution 3:\n";
        LongestSubstrWithoutRepChar longestSubstrWithoutRepChar;
        std::string s = "abcabcbb";
        std::cout << longestSubstrWithoutRepChar.lengthOfLongestSubstring(s) << '\n';
        s = "bbbbb";
        std::cout << longestSubstrWithoutRepChar.lengthOfLongestSubstring(s) << '\n';
        s = "pwwkew";
        std::cout << longestSubstrWithoutRepChar.lengthOfLongestSubstring(s) << '\n';
        s = "";
        std::cout << longestSubstrWithoutRepChar.lengthOfLongestSubstring(s) << '\n';
        s = "dvdf";
        std::cout << longestSubstrWithoutRepChar.lengthOfLongestSubstring(s) << '\n';
        std::cout << '\n';
    }

    {
        std::cout << "Solution 16:\n";
        ThreeSumClosest threeSumClosest;
        std::vector<int> int_vec = {-1, 2, 1, -4};
        std::cout << threeSumClosest.threeSumClosest(int_vec, 1) << '\n';
        int_vec = {0, 0, 0};
        std::cout << threeSumClosest.threeSumClosest(int_vec, 1) << '\n';
        int_vec = {-1000, -1000, -1000};
        std::cout << threeSumClosest.threeSumClosest(int_vec, 10000) << '\n';
        std::cout << '\n';
    }

    {
        std::cout << "Solution 5:\n";
        LongestPalindromicSubstr lps;
        std::string str = "babad";
        std::cout << lps.longestPalindrome(str) << '\n';
        str = "cbbd";
        std::cout << lps.longestPalindrome(str) << '\n';
        std::cout << '\n';
    }

    {
        std::cout << "Solution 214:\n";
        ShortestPalindrome shortestPalindrome;
        std::string s = "aacecaaa";
        std::cout << shortestPalindrome.shortestPalindrome(s) << '\n';
        s = "abcd";
        std::cout << shortestPalindrome.shortestPalindrome(s) << '\n';
        s = "adcba";
        std::cout << shortestPalindrome.shortestPalindrome(s) << '\n';
        s = "aababababababa";
        std::cout << shortestPalindrome.shortestPalindrome(s) << '\n';
        std::cout << '\n';
    }

    {
        std::cout << "Solution 259:\n";
        ThreeSumSmaller threeSumSmaller;
        std::vector<int> int_vec = {-2, 0, 1, 3};
        std::cout << threeSumSmaller.threeSumSmaller(int_vec, 2) << '\n';
        int_vec = {0};
        std::cout << threeSumSmaller.threeSumSmaller(int_vec, 0) << '\n';
        int_vec.clear();
        std::cout << threeSumSmaller.threeSumSmaller(int_vec, 0) << '\n';
        std::cout << '\n';
    }

    {
        std::cout << "Solution 516:\n";
        LongestPalindromicSubsequenceImproved lps;
        std::string s = "bbbab";
        std::cout << lps.longestPalindromeSubseq(s) << '\n';
        std::cout << '\n';
    }

    {
        std::cout << "Solution 1143:\n";
        LongestCommonSubsequenceNew lcs;
        std::string text1 = "abcde";
        std::string text2 = "ace";
        std::cout << lcs.longestCommonSubsequence(text1, text2) << '\n';
        text1 = "abc";
        text2 = "abc";
        std::cout << lcs.longestCommonSubsequence(text1, text2) << '\n';
        text1 = "abc";
        text2 = "def";
        std::cout << lcs.longestCommonSubsequence(text1, text2) << '\n';
        text1 = "abcd";
        text2 = "dbca";
        std::cout << lcs.longestCommonSubsequence(text1, text2) << '\n';
        text1 = "bsbininm";
        text2 = "jmjkbkjkv";
        std::cout << lcs.longestCommonSubsequence(text1, text2) << '\n';
        text1 = "bbbm";
        text2 = "mkb";
        std::cout << lcs.longestCommonSubsequence(text1, text2) << '\n';
        std::cout << '\n';
    }
    return 0;
}
