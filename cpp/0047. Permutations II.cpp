// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        vector<bool> visit(nums.size(), false);
        sort(nums.begin(), nums.end()); // 必须先排序才能去重
        dfs(nums, nums.size(), out, visit, res);
        return res;
    }
    
    void dfs(const vector<int>& nums, int level, vector<int>& out, vector<bool>& visit, vector<vector<int>>& res)
    {
        if (level == 0)
        {
            res.push_back(out);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            // 此处是去重的关键，保证前一个相同元素必须先使用过
            if (i > 0 && nums[i - 1] == nums[i] && !visit[i - 1])
            {
                continue;
            }
            
            if (!visit[i])
            {
                visit[i] = true;
                out.push_back(nums[i]);
                dfs(nums, level - 1, out, visit, res);
                out.pop_back();
                visit[i] = false;
            }
        }
    }
};
