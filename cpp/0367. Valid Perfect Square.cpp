// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Returns: True
// Example 2:

// Input: 14
// Returns: False
// Credits:
// Special thanks to @elmirap for adding this problem and creating all test cases.


// solution I:
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) 
            return true;

        long x = num / 2;
        long t = x * x;

        while (t > num) 
        {
            x /= 2;
            t = x * x;
        }

        // x * x <= num
        // (2x) * (2x) > num
        for (int i = x; i < 2 * x; ++i) 
        {
            if (i * i == num) 
                return true;
        }

        return false;
    }
}; 

// solution II: 二分法
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long t = mid * mid;
            
            if (t == num) 
                return true;
            else if (t < num) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        
        return false;
    }
};