// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(1, n, k, out, res); // 不需要visit数组
        return res;
    }
    
    void dfs(int start, int end, int level, vector<int>& out, vector<vector<int>>& res)
    {
        if (level == 0)
        {
            res.push_back(out);
            return;
        }
        
        for (int i = start; i <= end; i++)
        {
            out.push_back(i);
            dfs(i + 1, end, level - 1, out, res);
            out.pop_back();
        }
    }
};
