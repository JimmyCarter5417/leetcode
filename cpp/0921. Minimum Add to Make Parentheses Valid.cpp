// Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

 

// Example 1:

// Input: "())"
// Output: 1
// Example 2:

// Input: "((("
// Output: 3
// Example 3:

// Input: "()"
// Output: 0
// Example 4:

// Input: "()))(("
// Output: 4
 

// Note:

// S.length <= 1000
// S only consists of '(' and ')' characters.


// 左括号平衡度1，右括号平衡度-1
// 平衡度变为负值后，必须立刻恢复0，同时res++，否则会出错
// 平衡度变为正值则不会有这个问题
class Solution {
public:
    int minAddToMakeValid(string S) {
        int res = 0;
        int balance = 0;
        
        for (char ch: S)
        {
            if (ch == '(')
            {
                balance++;
            }
            else
            {
                balance--;
            }
            
            if (balance == -1)
            {
                res++;
                balance++;
            }
        }
        
        return res + balance;
    }
};