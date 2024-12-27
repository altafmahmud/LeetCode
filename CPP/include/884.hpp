// 884. Uncommon Words from Two Sentences
// Easy
// A sentence is a string of single-space separated words where each word consists only of lowercase letters.
// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
// Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

// Example 1:
// Input: s1 = "this apple is sweet", s2 = "this apple is sour"
// Output: ["sweet","sour"]

// Explanation:

// The word "sweet" appears only in s1, while the word "sour" appears only in s2.

// Example 2:
// Input: s1 = "apple apple", s2 = "banana"
// Output: ["banana"]

// Constraints:

// 1 <= s1.length, s2.length <= 200
// s1 and s2 consist of lowercase English letters and spaces.
// s1 and s2 do not have leading or trailing spaces.
// All the words in s1 and s2 are separated by a single space.

#pragma once

#include <vector>
#include <string>
#include <set>
#include <sstream>

class UncommonWords
{
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2)
    {
        std::set<std::string> dupWordSet;
        auto wordSet1 = tokenize(s1, dupWordSet);
        auto wordSet2 = tokenize(s2, dupWordSet);
        wordSet1 = removeDuplicates(wordSet1, dupWordSet);
        wordSet2 = removeDuplicates(wordSet2, dupWordSet);
        std::vector<std::string> uncommonVec;
        uncommonVec.reserve(wordSet1.size() + wordSet2.size());
        std::set_difference(wordSet1.begin(), wordSet1.end(), wordSet2.begin(), wordSet2.end(), std::back_inserter(uncommonVec));
        std::set_difference(wordSet2.begin(), wordSet2.end(), wordSet1.begin(), wordSet1.end(), std::back_inserter(uncommonVec));
        uncommonVec.shrink_to_fit();
        return uncommonVec;
    }

private:
    std::set<std::string> tokenize(const std::string &str, std::set<std::string> &dupWordSet)
    {
        std::set<std::string> wordSet;
        std::stringstream ss(str);
        std::string word;
        while (ss >> word)
        {
            const auto isInserted = wordSet.emplace(word).second;
            if (!isInserted)
            {
                dupWordSet.emplace(word);
            }
        }
        return wordSet;
    }

    std::set<std::string> removeDuplicates(const std::set<std::string> &wordSet, const std::set<std::string> &dupWordSet)
    {
        std::set<std::string> uniqueSet;
        std::set_difference(wordSet.begin(), wordSet.end(), dupWordSet.begin(), dupWordSet.end(), std::inserter(uniqueSet, uniqueSet.begin()));
        return uniqueSet;
    }
};
