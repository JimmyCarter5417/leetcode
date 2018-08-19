// Validate if a given string is numeric.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true

// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

class Solution {
public:
    bool isNumber(string s) {
		// [0-9]+ (.[0-9]+)? (E(+|-)? [0-9]+)?
		// 用状态机做比较简单
        enum INPUT 
        {
            SPACE = 0,
            SIGN,
            DIGIT, 
            E,
            DOT, 
            OTHERS
        };
        
        int stat[][10] = 
        {
             0,-1, 8, 8, 8,-1,-1, 8, 8,-1,
             1,-1,-1,-1,-1, 6,-1,-1,-1,-1,
             2, 2, 2, 4, 4, 7, 7, 7,-1, 4,
            -1,-1, 5, 5, 5,-1,-1,-1,-1,-1,
             9, 9, 3,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        };
        
        int status = 0;
        for (auto ch: s)
        {
            INPUT input;
            if (ch == ' ')
                input = SPACE;
            else if (ch == '+' || ch == '-')
                input = SIGN;
            else if (ch >= '0' && ch <= '9')
                input = DIGIT;
            else if (ch == 'e' || ch == 'E')
                input = E;
            else if (ch == '.')
                input = DOT;
            else 
                input = OTHERS;
                
            status = stat[input][status];
            if (status == -1)
                break;
        }
        
        return status == 2 || status == 3  || status == 4 || status == 7 || status == 8;
    }
};	