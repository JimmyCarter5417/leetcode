//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//Example:
//
//Input: 
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//Output: 4
//


class Solution {
public:
    int maximalSquare(const vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
        {
            return 0;
        }

        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.front().size() + 1));
        buildDp(matrix, dp); // 构建累加数组

        int res = 0;

        for (int i = 1; i <= matrix.size(); ++i)
        {
            for (int j = 1; j <= matrix.front().size(); ++j)
            {
                for (int k = 1; k <= min(i, j); ++k) // 遍历所有的正方形，关键在于k <= min(i, j)
                {
                    int area = getArea(i, j, i - k, j - k, dp);
                    if (area == k * k)
                    {
                        res = max(res, area);
                    }
                }
            }
        }

        return res;
    }

    void buildDp(const vector<vector<char>>& matrix, vector<vector<int>>& dp)
    {
        //assert(dp.size() == (matrix.size() + 1) && 
        //       dp.front().size() == (matrix.front().size() + 1));

        dp[0][0] = 0;

        for (int i = 1; i <= matrix.size(); ++i)
        {
            for (int j = 1; j <= matrix.front().size(); ++j)
            {
                dp[i][j] = matrix[i - 1][j - 1] -'0' - dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    int getArea(int x1, int y1, int x2, int y2, const vector<vector<int>>& dp)
    {
        //assert(x1 >= x2 && y1 >= y2);

        return dp[x1][y1] - dp[x2][y1] - dp[x1][y2] + dp[x2][y2];
    }
};

