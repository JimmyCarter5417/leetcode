// Given a balanced parentheses string S, compute the score of the string based on the following rule:

// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
 

// Example 1:

// Input: "()"
// Output: 1
// Example 2:

// Input: "(())"
// Output: 2
// Example 3:

// Input: "()()"
// Output: 2
// Example 4:

// Input: "(()(()))"
// Output: 6


class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;       
        stack<int> stk;
        stk.push(0); // 方便处理空栈的情况，后面就不需要判断了
        
        for (char ch: S)
        {
            if (ch == '(')
            {      
                stk.push(0);
            }
            else if (ch == ')')
            {            
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a + max(b * 2, 1));
            }
        }
        
        return stk.top();
    }
};