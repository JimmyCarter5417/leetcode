// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        int res = nums[0]; // 候选元素
        int cnt = 1; // 候选元素“绝对个数”
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == res)
            {
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    res = nums[i];
                    cnt = 1;
                }
            }
        }
        
        return res;
    }
};
