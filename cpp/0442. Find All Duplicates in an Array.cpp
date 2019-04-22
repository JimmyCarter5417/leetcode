// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
// Find all the elements that appear twice in this array.

// Could you do it without extra space and in O(n) runtime?

// Example:

// Input:
// [4,3,2,7,8,2,3,1]
// Output:
// [2,3]


// https://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        // 1 ≤ a[i] ≤ n 是关键
        // 以nums本身作为hash，每出现一次，就把n对应索引位置的值翻转
        for (int n: nums)
        {
            int idx = abs(n) - 1; // n可能已经被翻转过，要取绝对值
            
            if (nums[idx] < 0) // 已经翻转过，再次访问，即出现2次
            {
                res.push_back(idx + 1);
            }
            else // 未翻转过，需要翻转
            {
                nums[idx] = -nums[idx];
            }
        }
        
        return res;
    }
};
