// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example:

// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
 // [".Q..",  // Solution 1
  // "...Q",
  // "Q...",
  // "..Q."],

 // ["..Q.",  // Solution 2
  // "Q...",
  // "...Q",
  // ".Q.."]
// ]


class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        dfs(pos, 0, res);
        return res;
    }
    
    void dfs(vector<int>& pos, int row, int& res)
    {
        int n = pos.size();
        
        if (row == n)
        {
            ++res;
            return;
        }
        
        for (int i = 0; i < n; ++i)
        {
            pos[row] = i;
            
            if (isValid(pos, row, i))
                dfs(pos, row + 1, res);
                
            pos[row] = -1;
        }
    }
    
    bool isValid(vector<int>& pos, int row, int col)
    {
        for (int i = 0; i < row; ++i)
        {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i]))
                return false;
        }
        
        return true;
    }
};