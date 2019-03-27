// Given two sparse matrices A and B, return the result of AB.

// You may assume that A's column number is equal to B's row number.

// Example:

// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]

// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]


//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        // 稀疏矩阵，左行乘右列
        for (int i = 0; i < A.size(); ++i) 
        {
            for (int k = 0; k < A[0].size(); ++k) 
            {
                if (A[i][k] != 0) // 多两个为0的判断
                {
                    for (int j = 0; j < B[0].size(); ++j) 
                    {
                        if (B[k][j] != 0) // 多两个为0的判断
                            res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        
        return res;
    }
};