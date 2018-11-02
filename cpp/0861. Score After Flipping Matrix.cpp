// We have a two dimensional matrix A where each value is 0 or 1.

// A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

// After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

// Return the highest possible score.

 

// Example 1:

// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation:
// Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

// Note:

// 1 <= A.length <= 20
// 1 <= A[0].length <= 20
// A[i][j] is 0 or 1.


class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {   
        // 贪心算法，从左到右遍历各列，令每列包含的1最多
        int rows = A.size();
        int cols = A[0].size();
        int res = 0; // 视第一列全1
        
        for (int j = 0; j < cols; j++)
        {
            int tmp = 0;
            // 计算每一列与第一列相同的元素个数
            for (int i = 0; i < rows; i++)
            {
                if (A[i][j] == A[i][0])
                {
                    tmp++;
                }
            }
            // 取相同个数与不同个数中的最大值，若不同个数和较大，则翻转该列
            // 系数为2 ^ (cols - j - 1)
            res += max(tmp, rows - tmp) * (1 << (cols - j - 1));
        }
        
        // 第一列元素若为0，则翻转改行，令该行的值最大
        // 由于只需要计算总和，这一步就忽略了
        
        return res;
    }
};