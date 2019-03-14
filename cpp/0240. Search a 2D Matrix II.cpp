// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// Example:

// Consider the following matrix:

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.

// // Given target = 20, return false.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty())
            return false;
        
        int x = matrix.size() - 1; // 起始位置要是左下角或右上角的数字
        int y = 0;
        
        while (1) // 不能用二分法，只能O(M + N)
        {
            if (matrix[x][y] < target)
            {
                y++;
                
                if (y >= matrix.front().size())
                    return false;
            }    
            else if (matrix[x][y] > target)
            {
                x--;
                
                if (x < 0)
                    return false;
            } 
            else
            {
                return true;
            }    
        }
        
        return false;
    }
};
