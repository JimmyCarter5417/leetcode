// Given an integer, write a function to determine if it is a power of three.

// Follow up:
// Could you do it without using any loop / recursion?

// Credits:
// Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) 
        {
            n /= 3;
        }

        return n == 1;
        // return (n > 0 && 1162261467 % n == 0);
    }
};