// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

// Example:
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

// Note:
// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {       
        vector<vector<int>> res; // 也可以用set去重
        vector<int> out;       

        dfs(nums, 0, out, res);    
        
        return res;
    }
    
    void dfs(const vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res)
    {
        if (out.size() >= 2)
        {
            res.push_back(out);
        }
        
        unordered_set<int> s;
               
        for (int i = start; i < nums.size(); i++)
        {
            // 用set记录当前使用过的数字
            if (s.find(nums[i]) != s.end())
            {
                continue;
            }
            
            if (out.empty() || nums[i] >= out.back())
            {               
                out.push_back(nums[i]);
                s.insert(nums[i]);
                dfs(nums, i + 1, out, res);                
                out.pop_back();
            }
        }
    }
};