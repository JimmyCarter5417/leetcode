//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//
//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.front().empty())
            return 0;
            
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), INT_MAX));
        
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i)
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            
        for (int i = 1; i < triangle.size(); ++i)
            for (int j = 1; j <= i; ++j)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];

        // 找到最后一行最小值即可
        int res = INT_MAX;
        for (int i = 0; i < dp.back().size(); ++i)
            res = min(res, dp.back()[i]);
            
        return res;
    }
};

