//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
//
//Example 1:
//
//Input: "3+2*2"
//Output: 7
//Example 2:
//
//Input: " 3/2 "
//Output: 1
//Example 3:
//
//Input: " 3+5 / 2 "
//Output: 5
//Note:
//
//You may assume that the given expression is always valid.
//Do not use the eval built-in library function.
//


// 对于更一般的四则运算加括号的表达式，需要转换成逆波兰表达式
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        char sign = '+'; // 符号位预置为+
        stack<int> stk;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
                continue;
                
            int num = 0;
            while (isdigit(s[i]) && i < s.size())
            {
                num = 10 * num + s[i] - '0';
                ++i;
            }
            
            if (sign == '+')
            {
                stk.push(num);
            }
            else if (sign == '-')
            {
                stk.push(-num);
            }
            else if (sign == '*')
            {
                int prev = stk.top();
                stk.pop();
                stk.push(prev * num);
            }
            else if (sign == '/')
            {
                int prev = stk.top();
                stk.pop();
                stk.push(prev / num);
            }
           
            sign = s[i];
        }
        
        while (!stk.empty()) // 栈里只剩可直接相加的中间结果
        {
            res += stk.top();
            stk.pop();
        }
        
        return res;
    }
};

