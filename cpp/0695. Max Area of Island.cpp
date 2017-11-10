// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//
// Example 1:
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
// Example 2:
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty())
            return 0;
        
        int res = 0;
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid.front().size(), false));
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.front().size(); ++j)
            {
                if (grid[i][j] == 1 && !visit[i][j])
                {                    
                    res = max(res, dfs(grid, visit, i, j));
                }
            }
        }
        
        return res;
    }
    
    int dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visit, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid.front().size() || grid[x][y] == 0 || visit[x][y])
            return 0;        
       
        visit[x][y] = true;
        
        return 1 + dfs(grid, visit, x - 1, y)
                 + dfs(grid, visit, x + 1, y) 
                 + dfs(grid, visit, x, y - 1) 
                 + dfs(grid, visit, x, y + 1);
    }
};
