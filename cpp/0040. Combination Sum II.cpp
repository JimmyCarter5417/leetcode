// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, out, res);
        return res;
    }
    
    void dfs(const vector<int>& candidates, int level, int target, vector<int>& out, vector<vector<int>>& res)
    {
        if (level == candidates.size() || target <= 0)
        {
            if (target == 0)
            {
                res.push_back(out);
            }
            
            return;
        }
        
        for (int i = level; i < candidates.size(); i++)
        {
            // 关键在于这里的去重判断
            if (i > level && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            
            out.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i], out, res);
            out.pop_back();
        }
    }
};
