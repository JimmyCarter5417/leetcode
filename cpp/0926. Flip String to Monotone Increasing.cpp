// A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

// We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

// Return the minimum number of flips to make S monotone increasing.

 

// Example 1:

// Input: "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.
// Example 2:

// Input: "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.
// Example 3:

// Input: "00011000"
// Output: 2
// Explanation: We flip to get 00000000.
 

// Note:

// 1 <= S.length <= 20000
// S only consists of '0' and '1' characters.


class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int res = INT_MAX;
        int len = S.size();
        vector<int> sum(len + 1, 0);
        
        // sum[i+1]保存S[0, i]中1的个数
        for (int i = 0; i < len; i++)
        {
            if (S[i] == '1')
            {
                sum[i + 1] = sum[i] + 1;
            }
            else
            {
                sum[i + 1] = sum[i];
            }
        }
        // S[0, i]中1的个数为sum[i]
        // S(i, len - 1]中1的个数为sum[len] - sum[i]
        // S(i, len - 1]中0的个数为(len - i) - (sum[len] - sum[i])
        for (int i = 0; i <= len; i++)
        {
            int leftOnes = sum[i];
            int rightZeroes =  (len - i) - (sum[len] - sum[i]);
            res = min(res, leftOnes + rightZeroes);
        }
        
        return res;
    }
};