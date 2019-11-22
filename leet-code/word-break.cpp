#include <bits/stdc++.h>

using namespace std;

class Solution {
    std::unordered_set<std::string_view> cache; // cache to hold already checked prefixes (false values)

    bool startWith(std::string_view remaining, std::string_view prefix) {
        return remaining.size() >= prefix.size() &&
            std::string_view(remaining.data(), prefix.size()) == prefix;
    }

    template <typename Dictionary>
    bool check(std::string_view remaining, const Dictionary& dictionary) {
        if (remaining.empty()) {
            return true;
        }
        for (const auto& word : dictionary) {
            if (!startWith(remaining, word)) {
                continue;
            }
            std::string_view substring = remaining.substr(word.size());
            if (!cache.count(substring)) {
                if (check(substring, dictionary)) {
                    return true;
                }
                cache.insert(substring);
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, const vector<string>& wordDict) {
        return check(s, wordDict);
    }
};

int main() {
    std::cerr << Solution().wordBreak("leetcode", {"leet", "code"}) << std::endl;
    std::cerr << Solution().wordBreak("applepenapple", {"apple", "pen"}) << std::endl;
    std::cerr << Solution().wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) << std::endl;
    std::cerr << Solution().wordBreak("acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb", {"abbcbda","cbdaaa","b","dadaaad","dccbbbc","dccadd","ccbdbc","bbca","bacbcdd","a","bacb","cbc","adc","c","cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb","bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d","cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc","bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb","ab","aaaaa","acba","abbb"}) << std::endl;
    return 0;
}
