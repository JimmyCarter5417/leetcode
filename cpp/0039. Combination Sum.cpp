// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end()); // 注意先排序即可
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
            out.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], out, res);
            out.pop_back();
        }
    }
};
