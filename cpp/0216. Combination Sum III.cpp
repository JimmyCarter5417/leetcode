// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]


// 同I/II类似，递归即可
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(1, k, n, out, res);
        return res;
    }
    
    void dfs(int start, int num, int target, vector<int>& out, vector<vector<int>>& res)
    {
        if (num == 0 || target <= 0)
        {
            if (num == 0 && target == 0)
            {
                res.push_back(out);
            }
            
            return;
        }
        
        for (int i = start; i <= 9; i++)
        {
            out.push_back(i);
            dfs(i + 1, num - 1, target - i, out, res);
            out.pop_back();
        }
    }
};
