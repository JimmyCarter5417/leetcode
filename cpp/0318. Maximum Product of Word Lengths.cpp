// iven a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

// Example 1:

// Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16 
// Explanation: The two words can be "abcw", "xtfn".
// Example 2:

// Input: ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4 
// Explanation: The two words can be "ab", "cd".
// Example 3:

// Input: ["a","aa","aaa","aaaa"]
// Output: 0 
// Explanation: No such pair of words.


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<unsigned int> mask(words.size());    
        
        for (int i = 0; i < words.size(); i++)
        {
            for (char ch: words[i])
            {
                mask[i] |= (1<<(ch - 'a')); // 记录每个单词的掩码     
            }
            
            for (int j = 0; j < i; j++) // 冒泡查找
            {
                if (0 == (mask[i] & mask[j]))
                {
                    res = max(res, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        
        return res;
    }
};