// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// Example:

// Input: 4
// Output: [
 // [".Q..",  // Solution 1
  // "...Q",
  // "Q...",
  // "..Q."],

 // ["..Q.",  // Solution 2
  // "Q...",
  // "...Q",
  // ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        dfs(0, pos, res);
        return res;
    } 
    
    void dfs(int level, vector<int>& pos, vector<vector<string>>& res)
    {
        int n = pos.size();
        if (level == n)
        {
            res.push_back({});
            for (int v: pos)
            {
                string s(n, '.');
                s[v] = 'Q';
                res.back().push_back(s);
            }
            
            return;
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (isValid(pos, level, i))
            {
                pos[level] = i;
                dfs(level + 1, pos, res);
                pos[level] = -1;
            }
        }
    }
    
    bool isValid(const vector<int>& pos, int x, int y)
    {
        for (int i = 0; i < x; ++i)
        {
            if (y == pos[i] || abs(x - i) == abs(y - pos[i]))   
                return false;
        }
        
        return true;
    }
};