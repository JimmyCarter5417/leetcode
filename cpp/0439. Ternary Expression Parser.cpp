// Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the given expression is valid and only consists of digits 0-9, ?, :, T and F (T and Frepresent True and False respectively).

// Note:

// The length of the given string is ≤ 10000.
// Each number will contain only one digit.
// The conditional expressions group right-to-left (as usual in most languages).
// The condition will always be either T or F. That is, the condition will never be a digit.
// The result of the expression will always evaluate to either a digit 0-9, T or F.
 
// Example 1:
// Input: "T?2:3"
// Output: "2"
// Explanation: If true, then result is 2; otherwise result is 3. 

// Example 2:
// Input: "F?1:T?4:5"
// Output: "4"
// Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

//              "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
//           -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
//           -> "4"                                    -> "4"
 
// Example 3:
// Input: "T?T?F:5:3"
// Output: "F"
// Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:
//              "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
//           -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
//           -> "F"                                    -> "F"
 

class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;

        for (int i = expression.size() - 1; i >= 0; --i) // 从后往前
        {
            // O ? A : B
            char c = expression[i];

            if (!s.empty()) 
            {
                if (s.top() == '?') 
                {
                    s.pop(); // ?

                    char first = s.top(); 
                    s.pop(); // A

                    s.pop(); // :

                    char second = s.top(); 
                    s.pop(); // B
                    
                    s.push(c == 'T' ? first : second);
                }
            } 
            else 
            {
                s.push(c);
            }
        }

        return string(1, s.top());
    }
};