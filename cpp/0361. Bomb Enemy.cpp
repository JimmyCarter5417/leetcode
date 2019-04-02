// Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
// The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
// Note that you can only put the bomb at an empty cell.

// Example:

// For the given grid

// 0 E 0 0
// E 0 W E
// 0 E 0 0

// return 3. (Placing a bomb at (1,1) kills 3 enemies)
// Credits:
// Special thanks to @memoryless for adding this problem and creating all test cases.


// 有点意思
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) 
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int rowCnt; // rowCnt和colCnt没必要都用数组，其中一个可以用整数
        int colCnt[n];

        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (j == 0 || grid[i][j - 1] == 'W') // 对于一行，只需要处理墙的右边
                {
                    rowCnt = 0; // 这里要清零
                    for (int k = j; k < n && grid[i][k] != 'W'; ++k) 
                    {
                        rowCnt += grid[i][k] == 'E';
                    }
                }

                if (i == 0 || grid[i - 1][j] == 'W') // 对于一列，只需要处理墙的下边；对于墙右边的位置，可以直接用colCnt[j]加速，而不必再处理了
                {
                    colCnt[j] = 0; // 这里要清零
                    for (int k = i; k < m && grid[k][j] != 'W'; ++k) 
                    {
                        colCnt[j] += grid[k][j] == 'E';
                    }
                }

                if (grid[i][j] == '0') 
                {
                    res = max(res, rowCnt + colCnt[j]);
                }
            }
        }

        return res;
    }
};