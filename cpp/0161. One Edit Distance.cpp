// Given two strings S and T, determine if they are both one edit distance apart.


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // s/t的长度最多相差1，处理三种情况，二者最多只能有一个不同的字符 
        for (int i = 0; i < min(s.size(), t.size()); ++i)
        {
            if (s[i] != t[i]) 
            {
                if (s.size() == t.size()) 
                {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                else if (s.size() < t.size()) 
                {
                    return s.substr(i) == t.substr(i + 1);
                }
                else 
                {
                    return s.substr(i + 1) == t.substr(i);
                }
            }
        }
        
        return abs(s.size() - t.size()) == 1;
    }
};
