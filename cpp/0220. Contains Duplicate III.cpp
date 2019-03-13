// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
// Example 3:

// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.size() == k + 1) // 使用set维护一个滑动窗口，大小为k+1
            {
                s.erase(nums[i - k - 1]); // 达到最大窗口大小后，弹出最前面一个
            }
            
            set<long>::iterator itr = s.lower_bound((long)nums[i] - t); // 先查找第一个能插入的位置，即尝试与最小元素比较
            if (itr == s.end()) // 未找到，表示没有可以插入的位置，但不一定就不合法
            {
                if (!s.empty() && abs(*s.rbegin() - nums[i]) <= t) // 如果最大值符合要求，表示找到合法位置
                {
                    return true;
                }
            }
            else
            {
                if (abs(*itr - nums[i]) <= t) // 第一个能插入的位置，不一定合法，还要判断差值
                {
                    return true;
                }
            }
            
            s.insert(nums[i]); // 压入窗口
        }
        
        return false;
    }
};
