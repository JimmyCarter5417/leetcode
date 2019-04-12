// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

// Note:

// All letters in hexadecimal (a-f) must be in lowercase.
// The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
// The given number is guaranteed to fit within the range of a 32-bit signed integer.
// You must not use any method provided by the library which converts/formats the number to hex directly.

// Example 1:

// Input:
// 26
// Output:
// "1a"

// Example 2:

// Input:
// -1
// Output:
// "ffffffff"


class Solution {
public:
    string toHex(int num) {
        string res;
        unsigned int n = (unsigned int)num; // 使用无符号数右移
        
        for (int i = 0; i < 8 && n; ++i) // 最多循环8次，8 * 4 == 32
        {
            int t = (n & 0xf); // 取出低4位           
            res += (t < 10) ? ('0' + t) : ('a' + t - 10);
            
            n >>= 4; // n右移4位
        }
        
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};
