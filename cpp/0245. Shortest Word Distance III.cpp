// This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// word1 and word2 may be the same and they represent two individual words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “makes”, word2 = “coding”, return 1.
// Given word1 = "makes", word2 = "makes", return 3.

// Note:
// You may assume word1 and word2 are both in the list.


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = words.size(), p2 = -words.size(), res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) 
        {
            if (words[i] == word1) 
                p1 = word1 == word2 ? p2 : i; // 令p1始终指向前一个位置，即可避免问题I解法中word1/word2相同导致p1/p2相同的问题
            if (words[i] == word2) 
                p2 = i;
                
            res = min(res, abs(p1 - p2));
        }
        return res;
    }
};
