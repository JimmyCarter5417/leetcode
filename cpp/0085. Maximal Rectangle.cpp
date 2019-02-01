// iven a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example:

// Input:
// [
  // ["1","0","1","0","0"],
  // ["1","0","1","1","1"],
  // ["1","1","1","1","1"],
  // ["1","0","0","1","0"]
// ]
// Output: 6

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
        {
            return 0;
        }
        
        int res = 0;
        vector<int> heights(matrix[0].size(), 0);        
        
        for (int i = 0; i < matrix.size(); i++)
        {       
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1') 
                {
                    heights[j]++; // 递增该列高度
                }
                else
                {
                    heights[j] = 0; // 一定要清空
                }
            }
            
            // 计算该行及以上的区域
            res = max(res, helper(heights));
        }
        
        return res;
    }
    
    int helper(vector<int>& heights)
    {
        int res = 0;
        stack<int> monoStk;
        
        heights.push_back(0);
        
        for (int i = 0; i < heights.size(); i++)
        {
            while (!monoStk.empty() && heights[monoStk.top()] > heights[i])
            {
                int height = heights[monoStk.top()];
                monoStk.pop();
                int left = (monoStk.empty() ? -1 : monoStk.top());
                res = max(res, height * (i - left - 1));
            }
            
            monoStk.push(i);
        }
        
        heights.pop_back();
        
        return res;
    }
};