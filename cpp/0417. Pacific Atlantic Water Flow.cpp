// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

// Note:
// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.
// Example:

// Given the following 5x5 matrix:

//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic

// Return:
// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).


class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return {};
        }   
            
        int m = matrix.size();
        int n = matrix[0].size();
        // 全部初始化为false
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<pair<int, int>> res;
        
        // 第一列和最后一列
        for (int i = 0; i < m; ++i)
        {            
            dfs(matrix, pacific, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, n - 1);
        }
        // 第一行和最后一列
        for (int i = 0; i < n; ++i)
        {
            dfs(matrix, pacific, INT_MIN, 0, i);
            dfs(matrix, atlantic, INT_MIN, m - 1, i);
        }
        // 同时可以从上下和左右流出的位置
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i, j});
                }    
            }
        }
        
        return res;
    }
    
    // pre是关键
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& flag, int pre, int x, int y)
    {
        if (x < 0 || x > matrix.size() - 1 || y < 0 || y > matrix[0].size() - 1 || flag[x][y] || pre > matrix[x][y])
        {
            return ;
        }
        
        flag[x][y] = true;
        dfs(matrix, flag, matrix[x][y], x, y - 1);
        dfs(matrix, flag, matrix[x][y], x, y + 1);
        dfs(matrix, flag, matrix[x][y], x - 1, y);
        dfs(matrix, flag, matrix[x][y], x + 1, y);
    }
};