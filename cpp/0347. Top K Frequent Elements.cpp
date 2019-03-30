// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


// 注意：是“最高频”的K个数字，而不是最大的
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mm;//num, freq
        // 对于pair的greater或less，要依次比较first和second
        priority_queue<pair<int, int>> qq;//freq, num
        vector<int> res;
        
        // 记录每个数字出现的次数
        for (auto n: nums)
        {
            if (mm.end() == mm.find(n))
                mm[n] = 1;
            else
                ++mm[n];
        }
        
        // 创建最大堆
        for (auto p: mm)
        {
            qq.push({p.second, p.first});
        }
        
        // 从堆中弹出K个元素即可
        for (int i = 0; i < k; ++i)
        {
            res.push_back(qq.top().second);
            qq.pop();
        }
        
        return res;
    }
};