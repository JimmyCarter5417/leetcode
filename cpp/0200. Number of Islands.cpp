// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }
        
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();        
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 注意增加计数的时机即可
                if (!visit[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, visit);
                    res++;
                }
            }
        }
        
        return res;
    }
    
    void dfs(const vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visit)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visit[x][y] || grid[x][y] == '0')
        {
            return ;
        }
        
        visit[x][y] = true;
        dfs(grid, x + 1, y, visit);
        dfs(grid, x - 1, y, visit);
        dfs(grid, x, y + 1, visit);
        dfs(grid, x, y - 1, visit);
    }
};
