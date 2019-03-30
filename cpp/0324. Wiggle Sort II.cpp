// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

// Example 1:

// Input: nums = [1, 5, 1, 1, 6, 4]
// Output: One possible answer is [1, 4, 1, 5, 1, 6].
// Example 2:

// Input: nums = [1, 3, 2, 2, 3, 1]
// Output: One possible answer is [2, 3, 1, 3, 1, 2].
// Note:
// You may assume all input has valid answer.

// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?


// solution I: O(NlgN)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end()); // 先排序
        int left = (tmp.size() + 1) / 2 - 1;
        int right = tmp.size() - 1;
        
        // 将后半部分放到奇数位置，前半部分放到偶数位置
        // 这应该是最严格的匹配方式，如果存在解法的话，必然符合
        for (int i = 0; i < tmp.size(); ++i)
        {
            if (i&1)
                nums[i] = tmp[right--];
            else
                nums[i] = tmp[left--];
        }
    }
};

// solution II: O(N)
// https://leetcode.com/problems/wiggle-sort-ii/discuss/77682/Step-by-step-explanation-of-index-mapping-in-Java
