// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Example:
// Input:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
// Output: 16

// Explanation: The perimeter is the 16 yellow stripes in the image below:


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j])
                {
                    int a, b, c, d;
                
                    // 上
                    if (i == 0)
                        a = 1;
                    else
                        a = grid[i-1][j] ? 0 : 1;
                    
                    // 左
                    if (j == 0)
                        b = 1;
                    else
                        b = grid[i][j-1] ? 0 : 1;
                    
                    // 下
                    if (j == grid[0].size() - 1)
                        c = 1;
                    else
                        c = grid[i][j+1] ? 0 : 1;
                    
                    // 右
                    if (i == grid.size() - 1)
                        d = 1;
                    else
                        d = grid[i+1][j] ? 0 : 1;
                    
                    res += a + b + c + d;
                }
            }
        }
        
        return res;
    }
};