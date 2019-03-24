// Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.

// Formally, we can partition the array if we can find indexes i+1 < j with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])

// Example 1:

// Input: [0,2,1,-6,6,-7,9,1,2,0,1]
// Output: true
// Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
// Example 2:

// Input: [0,2,1,-6,6,7,9,-1,2,0,1]
// Output: false
// Example 3:

// Input: [3,3,6,5,-2,2,5,1,-9,4]
// Output: true
// Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 
// Note:

// 3 <= A.length <= 50000
// -10000 <= A[i] <= 10000


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if (A.empty())
        {
            return false;
        }
        
        int n = A.size();
        vector<int> sum(n);
        
        sum[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + A[i]; // 累加数组加速计算
        }
        
        for (int i = 0; i < n - 1; i++)
        {
            if (sum[n - 1]  != 3 * sum[i]) // 总和不是第一部分的三倍，即可忽略，优化
            {
                continue;
            }
            
            for (int j = i + 1; j < n; j++)
            {
                int s1 = sum[i];
                int s2 = sum[j - 1] - sum[i];
                int s3 = sum[n - 1] - sum[j - 1];
                                
                if (s1 == s2 && s2 == s3)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
