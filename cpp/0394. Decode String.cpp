// Given an encoded string, return it's decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".


class Solution {
public:
    string decodeString(string s) {
        stack<int> stkNum; // 用两个栈分别记录num和str
        stack<string> stkStr;
        
        int num = 0;
        string str;
        for (char ch: s)
        {
            if (isdigit(ch))
            {
               num = num * 10 + ch - '0'; 
            }
            else if (ch == '[')
            {
                stkNum.push(num);
                stkStr.push(str);
                
                num = 0;
                str.clear();
            }
            else if (ch == ']')
            {
                string t = stkStr.top();
                stkStr.pop();
                int n = stkNum.top();
                stkNum.pop();
                
                for (int i = 0; i < n; i++)
                {
                    t += str;
                }
                str = t;
            }
            else
            {
                str.push_back(ch);
            }
        }
        
        return stkStr.empty() ? str : stkStr.top();
    }
};
