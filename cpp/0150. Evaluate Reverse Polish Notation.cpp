//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Note:
//
//Division between two integers should truncate toward zero.
//The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
//Example 1:
//
//Input: ["2", "1", "+", "3", "*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9
//Example 2:
//
//Input: ["4", "13", "5", "/", "+"]
//Output: 6
//Explanation: (4 + (13 / 5)) = 6
//Example 3:
//
//Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//Output: 22
//Explanation: 
//  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
//


// solution I：递归
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int end = tokens.size() - 1;
        return dfs(tokens, end);
    }

    // end一定要传引用
    int dfs(const vector<string>& tokens, int& end)
    {
        string str = tokens[end];
         
        if (str == "+" || str == "-" || str == "*" || str == "/")
        {
            // 注意v2、v1的计算顺序
            int v2 = dfs(tokens, --end);
            int v1 = dfs(tokens, --end);
            if (str == "+")
                return v1 + v2;
            if (str == "-")
                return v1 - v2;
            if (str == "*")
                return v1 * v2;
            if (str == "/")
                return v1 / v2;
        }
        else
        {
            return stoi(str); // 此处也是终止条件，不需要额外判断
        }        
    }
};

// solution II：迭代
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& t: tokens)
        {
            if (t == "+" || t == "-" || t == "*" || t == "/")
            {
                int rhs = stk.top();
                stk.pop();
                int lhs = stk.top();
                stk.pop();
                
                int tmp = 0;
                
                if (t == "+")
                    tmp = lhs + rhs;
                if (t == "-")
                    tmp = lhs - rhs;
                if (t == "*")
                    tmp = lhs * rhs;
                if (t == "/")
                    tmp = lhs / rhs;
                    
                stk.push(tmp);
            }
            else
            {
                stk.push(atoi(t.c_str()));
            }
        }
        
        return stk.top();
    }
};

