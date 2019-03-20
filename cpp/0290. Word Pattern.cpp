// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Example 1:

// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
// Example 2:

// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
// Example 4:

// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream iss(str);        
        string s;
        int i = 0;
        
        while (iss>>s && i < pattern.size())
        {                
            char ch = pattern[i];
            auto itr1 = m1.find(ch);
            auto itr2 = m2.find(s);
            
            if (itr1 == m1.end() && itr2 == m2.end())
            {
                m1[ch] = i; // 更新索引，与前面某一题相同的思想
                m2[s] = i;
            }
            else if (itr1 != m1.end() && itr2 != m2.end())
            {
                if (itr1->second != itr2->second) // 必须相同
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            
            i++;
            s.clear();
        }
        
        return i == pattern.size() && s.empty(); // 循环结束也可能不符合条件
    }
};