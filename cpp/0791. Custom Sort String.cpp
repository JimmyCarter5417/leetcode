// S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

// S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

// Return any permutation of T (as a string) that satisfies this property.

// Example :
// Input: 
// S = "cba"
// T = "abcd"
// Output: "cbad"
// Explanation: 
// "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
// Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
 

// Note:

// S has length at most 26, and no character is repeated in S.
// T has length at most 200.
// S and T consist of lowercase letters only.

class Solution {
public:
    string customSortString(string S, string T) {
        int m[256];// 字典字符计数
        for (int i = 0; i < sizeof(m) / sizeof(int); i++)
        {
            m[i] = -1;// 初始化-1表示不存在该字符
        }
        
        vector<char> v;// 字典
        string res, extra;
        
        for (int i = 0; i < S.size(); i++)
        {
            v.push_back(S[i]);// 加入字典
            m[S[i]] = 0;// 0表示字典里有这个字符
        }    
        
        for (char ch: T)
        {
            if (-1 == m[ch])// 字典没这个字符则存入extra
            {                
                extra.push_back(ch);
            }
            else// 字典有这个字符
            {
                m[ch]++;   
            }
        }
        
        for (int i = 0; i < v.size(); i++)
        {
            if (m[v[i]] > 0)// 字典字符计数大于0，则依次输出到res
                res.append(m[v[i]], v[i]);
        }
        
        res.append(extra);// 最后再添加extra        
        return res;
    }
};
