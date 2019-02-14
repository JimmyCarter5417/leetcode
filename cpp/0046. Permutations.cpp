// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())
        {
            return res;
        }
        vector<int> out;
        vector<bool> visit(nums.size(), false);
        // 与Permutations II类似，只是没有重复元素，只要用visit数组记录一下即可
        dfs(nums, nums.size(), visit, out, res);
        return res;
    }
    
    void dfs(const vector<int>& nums, int level, vector<bool>& visit, vector<int>& out, vector<vector<int>>& res)
    {
        if (level <= 0)
        {
            res.push_back(out);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visit[i])
            {
                visit[i] = true;
                out.push_back(nums[i]);
                dfs(nums, level - 1, visit, out, res);
                out.pop_back();
                visit[i] = false;
            }
        }
    }
};
