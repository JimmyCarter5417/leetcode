// Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

// Note:
// If n is the length of array, assume the following constraints are satisfied:

// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
// Examples:

// Input:
// nums = [7,2,5,10,8]
// m = 2

// Output:
// 18

// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.


// hard! 以范围作为二分判断的标准
// https://leetcode.com/problems/split-array-largest-sum/discuss/89819/C%2B%2B-Fast-Very-clear-explanation-Clean-Code-Solution-with-Greedy-Algorithm-and-Binary-Search
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0;
        long long right = 0;
        
        for (int n: nums)
        {
            left = max(left, (long long)n); // 最大值
            right += n; // 总和
        }
        
        while (left < right)
        {
            long long mid = left + (right - left) / 2; // 可能用于分组和的最大值
            
            if (fun(nums, m - 1, mid)) 
            {
                right = mid; // 分组成功，则需要减小最大值
            }
            else
            {
                left = mid + 1; // 分组失败，则需要增大最大值
            }
        }
        
        return left;
    }
    
    bool fun(const vector<int>& nums, int cuts, int mx)
    {
        long long sum = 0;
        
        for (int n: nums)
        {
            if (sum + n <= mx)
            {
                sum += n;
            }
            else
            {
                if (--cuts < 0) // cuts变为负数，说明这个mx太小了
                {
                    return false;
                }
                
                sum = n;
            }
        }
        
        // 加入mx太大了，此处的cuts会大于0，认为是合法分组，继续二分处理即可
        return true;
    }
};