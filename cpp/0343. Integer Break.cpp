// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

// Example 1:

// Input: 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.
// Example 2:

// Input: 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
// Note: You may assume that n is not less than 2 and not larger than 58.


// 数字4拆成2+2，乘积最大，为4。
// 数字5拆成3+2，乘积最大，为6。
// 数字6拆成3+3，乘积最大，为9。
// 数字7拆为3+4，乘积最大，为12。
// 数字8拆为3+3+2，乘积最大，为18。
// 数字9拆为3+3+3，乘积最大，为27。
// 数字10拆为3+3+4，乘积最大，为36。
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3) 
            return n - 1;

        int res = 1;

        while (n > 4) // 尽可能多拆3
        {
            res *= 3;
            n -= 3;
        }

        return res * n;
    }
};