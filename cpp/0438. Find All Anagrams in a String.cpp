// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

// The order of output does not matter.

// Example 1:
// Input:
// s: "cbaebabacd" p: "abc"
// Output:
// [0, 6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2:
// Input:
// s: "abab" p: "ab"
// Output:
// [0, 1, 2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".


// 滑动窗口模型
// https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m[256] = {0};
        int left = 0;
        int right = 0;
        int cnt = p.size();
        
        for (char ch: p)
        {
            m[ch]++;
        }
        
        while (right < s.size()) // right指向当前窗口右边界
        {
            if (m[s[right]] >= 1) // right刚滑入窗口，需要处理
            {
                cnt--; // 在pattern串之中
            }                
            m[s[right]]--; // 不管右边界字符是否在pattern串之中，都将其计数减一；对于不存在的字符，这里会将计数减为负数
                                            
            if (cnt == 0) // 找到合适的窗口
            {
                res.push_back(left);
            }
            
            if (right - left + 1 == p.size())
            {
                if (m[s[left]] >= 0) // 代表左边界字符已被使用，弹出的时候需要归还总的计数
                {
                    cnt++;   
                }                
                m[s[left]]++; // 不管怎样，计数都需要加一
                
                left++; // 左边界右移
            }
            
            right++; // 右边界右移
        }
        
        return res;
    }
};