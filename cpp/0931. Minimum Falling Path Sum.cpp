// Given a square array of integers A, we want the minimum sum of a falling path through A.

// A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

// Example 1:

// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: 12
// Explanation: 
// The possible falling paths are:
// [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
// [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
// [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
// The falling path with the smallest sum is [1,4,7], so the answer is 12.

 

// Note:

// 1 <= A.length == A[0].length <= 100
// -100 <= A[i][j] <= 100


// DFS TLE
/*class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int res = INT_MAX;
        
        for (int i = 0; i < A.front().size(); i++)
        {
            res = min(res, dfs(A, 0, i));
        }
        
        return res;
    }
    
    int dfs(const vector<vector<int>>& A, int row, int col)
    {
        int rows = A.size();
        int cols = A.front().size();
        int res = INT_MAX;
        int a = INT_MAX;
        int b = INT_MAX;
        int c = INT_MAX;
        
        if (row == rows)
            return 0;
        
        a = dfs(A, row + 1, col);
        if (col != 0)
            b = dfs(A, row + 1, col - 1);
        if (col != cols - 1)
            c = dfs(A, row + 1, col + 1);               
        
        return A[row][col] + min(a, min(b, c));
    }
};*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        // 由下至上计算dp
        int res = INT_MAX;
        int rows = A.size();
        int cols = A.front().size();        
        vector<vector<int>> dp(rows, vector<int>(cols));
        // 先填充最后一行
        for (int i = 0; i < A.back().size(); i++)
        {
            dp[rows - 1][i] = A[rows - 1][i];
        }
        
        for (int i = rows - 2; i >= 0; i--)
        {
            for (int j = 0; j < cols; j++)
            {
                int tmp = dp[i + 1][j];
                if (j != 0)
                    tmp = min(tmp, dp[i + 1][j - 1]);
                if (j != cols - 1)
                    tmp = min(tmp, dp[i + 1][j + 1]);
                // dp[i][j] = A[i][j] + min(dp[i+1][j], dp[i+1][j-1], dp[i+1][j+1])
                dp[i][j] = A[i][j] + tmp;
            }
        }
        
        for (int i = 0; i < cols; i++)
        {
            res = min(res, dp[0][i]);
        }
        
        return res;
    }
};