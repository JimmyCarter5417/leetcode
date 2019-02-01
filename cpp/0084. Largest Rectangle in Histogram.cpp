// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

// The largest rectangle is shown in the shaded area, which has area = 10 unit. 

// Example:

// Input: [2,1,5,6,2,3]
// Output: 10

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> monoStk; // 单调递增栈
        // 入栈：维护单调递增
        // 出栈：计算矩形面积
        
        heights.push_back(0); // 方便最后统一处理出栈
        
        for (int i = 0; i < heights.size(); i++)
        {
            while (!monoStk.empty() && heights[monoStk.top()] > heights[i])
            {
                int height = heights[monoStk.top()]; // 以出栈位置为高度
                monoStk.pop(); // 注意：这里要先出栈，因为需要计算的左边界在栈顶第二位置
                int left = (monoStk.empty() ? -1 : monoStk.top()); // 上面有pop()，要考虑空栈       
                res = max(res, height * (i - left - 1));                
            }
            
            monoStk.push(i);
        }        
        
        return res;
    }
};