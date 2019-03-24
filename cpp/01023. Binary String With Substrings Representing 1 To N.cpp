// Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.

// Example 1:

// Input: S = "0110", N = 3
// Output: true
// Example 2:

// Input: S = "0110", N = 4
// Output: false
 
// Note:

// 1 <= S.length <= 1000
// 1 <= N <= 10^9


class Solution {
public:
    bool queryString(string S, int N) {       
        for (int i = 1; i <= N; i++)
        {
            string str = iToBinStr(i); // 简单遍历所有数字的对应的二进制字符串即可
            if (S.find(str) == S.end())
            {
                return false;
            }
        }
        
        return true;
    }
    
    string iToBinStr(int n)
    {
        string res;
        
        while (n)
        {
            if (n & 1)
            {
                res.push_back('1');
            }
            else
            {
                res.push_back('0');
            }
            
            n = (n >> 1);
        }
        
        reverse(res.begin(), res.end()); // 注意反转
        return res;
    }
};
