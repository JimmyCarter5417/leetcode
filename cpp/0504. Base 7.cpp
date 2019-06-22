// Given an integer, return its base 7 string representation.

// Example 1:
// Input: 100
// Output: "202"

// Example 2:
// Input: -7
// Output: "-10"

// Note: The input will be in range of [-1e7, 1e7].


class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0)
            return "-" + convertToBase7(-num);
            
        string res;
        while (num)
        {
            res += to_string(num % 7); // 高位在后
            num /= 7;
        }
        
        reverse(res.begin(), res.end()); // 一次翻转即可
        return res;
    }
};