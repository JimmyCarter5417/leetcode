// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Note:

// Each element in the result must be unique.
// The result can be in any order.


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {        
        set<int> ss(nums1.begin(), nums1.end());
        set<int> res;
        
        for (auto n: nums2)
        {
            if (ss.end() != ss.find(n)) // 利用set简单查找即可
                res.insert(n);
        }
        
        return vector<int>(res.begin(), res.end());
    }
};