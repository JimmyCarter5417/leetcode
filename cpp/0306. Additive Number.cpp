// Additive number is a string whose digits can form additive sequence.

// A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

// Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

// Example 1:

// Input: "112358"
// Output: true 
// Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
//              1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// Example 2:

// Input: "199100199"
// Output: true 
// Explanation: The additive sequence is: 1, 99, 100, 199. 
//              1 + 99 = 100, 99 + 100 = 199
// Follow up:
// How would you handle overflow for very large input integers?


class Solution {
public:
    bool isAdditiveNumber(string num) {
        // 暴力搜索：根据前两个数字即可得到唯一addictive num序列
        for (int i = 1; i < num.size(); ++i)
        {
            for (int j = i + 1; j < num.size(); ++j)
            {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - i);
                
                // 先过滤非法情况
                if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0'))
                    continue;
                
                long long d1 = atoll(s1.c_str()); // 计算d1/d2
                long long d2 = atoll(s2.c_str());
                long long d3 = d1 + d2;
                string now = s1 + s2 + to_string(d3);
                
                while (now.size() < num.size()) // 根据d1/d2生成最终的字符串
                {
                    d1 = d2;
                    d2 = d3;
                    d3 = d1 + d2;
                    now += to_string(d3);
                }
                
                if (now == num) // 生成的字符串和给定的相同，即找到了正确组合
                    return true;
            }
        }
        
        return false;
    }
};
