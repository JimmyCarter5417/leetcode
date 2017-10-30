// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;
        
        stack<char> stk;
        for (auto ch: s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
              stk.push(ch);
            }
            else
            {
                if (stk.empty())
                    return false;
                    
                char tmp = stk.top();
                stk.pop();
                
                if ((ch == ')' && tmp != '(') ||
                    (ch == ']' && tmp != '[') ||
                    (ch == '}' && tmp != '{'))
                    return false;
            }
        }
        
        return stk.empty();
    }
};
