// Given an integer n, return 1 - n in lexicographical order.

// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        // 深度优先遍历，依次遍历1/2/3...打头的所有数字
        for (int i = 1; i <= 9; ++i)
            dfs(i, n, res);
            
        return res;
    }
    
    void dfs(int cur, int n, vector<int>& res)
    {
        if (cur > n)
            return;
            
        res.push_back(cur);

        for (int i = 0; i <= 9; ++i)
        {
            dfs(10 * cur + i, n, res); // 下一层要乘10
        }
    }
};