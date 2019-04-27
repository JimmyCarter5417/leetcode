// Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

// Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].


// 相似的问题：496 503 556
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<int> stk;
        
        for (int i = T.size() - 1; i >= 0; i--) // 从后往前遍历
        {
            while (!stk.empty() && T[i] >= T[stk.top()]) // 单调递减栈
            {
                stk.pop();
            }
            
            if (stk.empty())
            {
                res[i] = 0;
            }
            else
            {
                res[i] = stk.top() - i;
            }
            
            stk.push(i); // 保存索引
        }
        
        return res;
    }
};