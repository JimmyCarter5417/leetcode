// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.


class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int flag = 0;
        
        while(i >= 0 || j >= 0)
        {
            int a = (i >= 0) ? num1[i] - '0' : 0;
            int b = (j >= 0) ? num2[j] - '0' : 0;
            int sum = a + b + flag;
            
            res.push_back(sum % 10 + '0');
            
            flag = sum / 10;            
            i--;
            j--;
        }
        
        if (flag)
        {
            res.push_back(1 + '0');
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
