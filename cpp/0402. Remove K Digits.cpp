// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.


class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        
        for (char ch: num)
        {
            while (!res.empty() && res.back() > ch && k) // 单调递增栈
            {
                res.pop_back();
                k--; // 最多只能删除k个字符
            }
            
            res.push_back(ch);
        }
        
        // 注意：上面构建的单调递增栈，有可能未删除任何字符，如12345
        // 这里需要手动弹出末尾最大的k个字符，也可以用res.resize(n - k)
        while (!res.empty() && k)
        {
            res.pop_back();
            k--;
        }
        
        size_t pos = res.find_first_not_of('0');
        if (pos == string::npos) // 有可能剩余的字符只有0
        {
            return "0";
        }
        else // 有可能前面是0，如000123
        {
            return res.substr(pos);
        }        
    }
};
