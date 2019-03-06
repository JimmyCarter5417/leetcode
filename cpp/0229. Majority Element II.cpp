// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Note: The algorithm should run in linear time and in O(1) space.

// Example 1:

// Input: [3,2,3]
// Output: [3]
// Example 2:

// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {        
        vector<int> res;
        // 用两个候选者，res最多只有两个数据
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int n: nums)
        {  
            // 处理顺序很重要
            if (n == candidate1)
            {
                cnt1++;
            }
            else if (n == candidate2)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                cnt1 = 1;
                candidate1 = n;
            }
            else if (cnt2 == 0)
            {
                cnt2 = 1;
                candidate2 = n;
            }            
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        // 先计数
        for (int n: nums)
        {
            if (n == candidate1)
            {
                cnt1++;
            }
            else if (n == candidate2)
            {
                cnt2++;
            }
        }
        // 确认候选者
        if (cnt1 > nums.size() / 3)
        {
            res.push_back(candidate1);
        }
        if (cnt2 > nums.size() / 3)
        {
            res.push_back(candidate2);
        }
        
        return res;
    }
};
