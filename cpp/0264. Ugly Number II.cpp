// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note:  

// 1 is typically treated as an ugly number.
// n does not exceed 1690.


// todo
class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> res(1, 1);
        while (res.size() < n)
        {
            int m2 = 2 * res[i2];
            int m3 = 3 * res[i3];
            int m5 = 5 * res[i5];
            int val = min(min(m2, m3), m5);
            res.push_back(val);
            if (val == m2) i2++;
            if (val == m3) i3++;
            if (val == m5) i5++;
        }
        
        return res.back();
    }
};