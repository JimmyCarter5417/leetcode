// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(nums, 0, out, res);
        return res;
    }
    
    void dfs(const vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res)
    {
        // 此处的push_back是关键，因为要记录递归过程中所有的子串
        res.push_back(out);
        
        for (int i = start; i < nums.size(); i++)
        {
            out.push_back(nums[i]);
            dfs(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};
