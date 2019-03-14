// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

// Example:

// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 

// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

// Follow up:
// Could you solve it in linear time?


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // 单调双向队列
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k) // 此处仅代表窗口达到最大值，需要强制弹出最前面的数字
            {
                // res.push_back(nums[dq.front()]); // 不能在此处添加
                dq.pop_front();
            }
            
            while (!dq.empty() && nums[dq.back()] < nums[i]) // 保证队列从前往后单调递减
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= k - 1) // 窗口长度之后，都要push_back，队列首部即为窗口最大值
            {
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};
