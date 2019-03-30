// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

// Example 1:

// Input: 16
// Output: true
// Example 2:

// Input: 5
// Output: false
// Follow up: Could you solve it without loops/recursion?


// solution I: 简单循环
class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num && (num % 4 == 0)) 
        {
            num /= 4;
        }
        return num == 1;
    }
};

// solution II: n&(n-1)可判断是否是2的次方，再判断特定位即可
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};