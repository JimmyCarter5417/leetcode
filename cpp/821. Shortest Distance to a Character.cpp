// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

// Example 1:

// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

// Note:

// S string length is in [1, 10000].
// C is a single character, and guaranteed to be in string S.
// All letters in S and C are lowercase.

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.size());
        
        int pos = -1;
        for (int i = 0; i < S.size(); i++)
        {
            if (C == S[i])            
                pos = i;
            
            if (pos == -1)
                res[i] = INT_MAX;
            else
                res[i] = i - pos;
        }
        
        pos = -1;
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (C == S[i])            
                pos = i;
            
            if (pos != -1)
                res[i] = min(res[i], pos - i);            
        }        
        
        return res;
    }
};
