//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
//
//Example 1:
//
//Input: "1 + 1"
//Output: 2
//Example 2:
//
//Input: " 2-1 + 2 "
//Output: 3
//Example 3:
//
//Input: "(1+(4+5+2)-3)+(6+8)"
//Output: 23
//Note:
//You may assume that the given expression is always valid.
//Do not use the eval built-in library function.
//


class Solution {
public:
    int calculate(string s) {
        int res = 0;
        vector<int> sign(2, 1); // 此处必须为2，因为首部可能消耗一个符号，后面的字符也需要读取前面最后一个符号，因此至少要预埋2个符号，如1+1
        
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                int num = 0;
                while (isdigit(s[i]) && i < s.size())
                {
                    num = num * 10 + s[i++] - '0';
                }
                i--;
                
                res += sign.back() * num;
                sign.pop_back(); // 每个数字要消耗一个符号位
            }
            else if (s[i] == ')')
            {
                sign.pop_back(); // 右括号也要弹出左括号的符号位
            }
            else if (s[i] == '(' || s[i] == '+') // + - ( 都需要添加符号位
            {
                sign.push_back(sign.back());
            }
            else if (s[i] == '-')
            {
                sign.push_back(-1 * sign.back());
            }    
        }
        
        return res;
    }
};


