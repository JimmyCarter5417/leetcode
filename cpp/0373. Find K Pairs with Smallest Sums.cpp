// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

// Define a pair (u,v) which consists of one element from the first array and one element from the second array.

// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]] 
// Explanation: The first 3 pairs are returned from the sequence: 
//              [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// Example 2:

// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [1,1],[1,1]
// Explanation: The first 2 pairs are returned from the sequence: 
//              [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// Example 3:

// Input: nums1 = [1,2], nums2 = [3], k = 3
// Output: [1,3],[2,3]
// Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]


// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84566/share-my-solution-which-beat-9642
// 与378. Kth Smallest Element in a Sorted Matrix相同的思路
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {        
        vector<pair<int, int>> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        auto cmp = [&](const pair<int, int>& p1, const pair<int, int>& p2)
                   {
                       return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
                   };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); // 最小堆，按照和排序
        
        if (nums1.empty() || nums2.empty() || k <= 0) // 注意先判断是否为空
        {
            return res;
        }
        
        for (int i = 0; i < n2; i++)
        {
            pq.push({0, i});
        }
        
        for (int i = 0; i < min(k, n1 * n2); i++) // k可能很大，但最多只能处理n1 * n2次
        {
            pair<int, int> t = pq.top();
            pq.pop();
            
            res.push_back({nums1[t.first], nums2[t.second]});
            
            if (t.first != n1 - 1) // first加1，压入堆
            {
                pq.push({t.first + 1, t.second});
            }
        }
        
        return res;
    }
};
