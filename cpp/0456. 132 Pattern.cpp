// Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

// Note: n will be less than 15,000.

// Example 1:
// Input: [1, 2, 3, 4]
// Output: False
// Explanation: There is no 132 pattern in the sequence.

// Example 2:
// Input: [3, 1, 4, 2]
// Output: True
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

// Example 3:
// Input: [-1, 3, 2, 0]
// Output: True
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


// 单调栈
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN; // 代表132的2
        stack<int> stk;
        
        for (int i = nums.size() - 1; i >= 0; --i) // 从后往前遍历
        {            
            if (nums[i] < s3) // 找到了1
            {
                return true;
            }    
            
            while (!stk.empty() && nums[i] > stk.top()) // 单调递增栈，弹出小于num的数字
            {
                s3 = stk.top(); // 注意更新s3，保证其最大
                stk.pop();
            }
                
            stk.push(nums[i]); // num这个数字太大了，需要入栈
        }
        
        return false;
    }
};