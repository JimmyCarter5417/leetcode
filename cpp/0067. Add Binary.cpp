// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"


class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0; // 注意处理进位即可
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while (i >= 0 || j >= 0)
        {
            int n1 = (i >= 0 ? a[i] - '0' : 0);
            int n2 = (j >= 0 ? b[j] - '0' : 0);
            int t = n1 + n2 + carry;
            res.push_back('0' + t % 2);
            carry = t / 2;
            
            if (i >= 0)
            {
                i--;
            }
            if (j >= 0)
            {
                j--;
            }
        }
        
        if (carry)
        {
            res.push_back('1');
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
