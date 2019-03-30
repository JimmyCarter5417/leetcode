// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

// Note:
// A naive algorithm of O(n2) is trivial. You MUST do better than that.

// Example:

// Input: nums = [-2,5,-1], lower = -2, upper = 2,
// Output: 3 
// Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long> s; // 一定要用multset，可能会有相同的sum
        long sum = 0;
        int res = 0;
        
        s.insert(0); // 这句话是必须的，含义就是空的数组和为0
        // 累加数组的思想
        // lower <= sum[j] - sum[i] <= upper
        // sum[j] - upper =< sum[i] <= sum[j] - lower
        // 找到sum[i]的个数！
        for (int n: nums)
        {
            sum += n;
            res += distance(s.lower_bound(sum - upper), s.upper_bound(sum - lower));
            s.insert(sum);
        }
        
        return res;
    }
};