// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
// Given two integers x and y, calculate the Hamming distance.

// Note:
// 0 ≤ x, y < 231.

// Example:
// Input: x = 1, y = 4
// Output: 2

// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// The above arrows point to positions where the corresponding bits are different.


class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int t = (x^y);
        while (t)
        {
            ++res;
            t = (t&(t-1));
            // n&(n-1)：将n的二进制表示中的最低位为1的改为0
            // n&-n：取出n的二进制中最右边为1的部分
        }
        
        return res;
    }
};