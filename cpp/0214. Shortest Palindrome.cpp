//Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
//Example 1:
//
//Input: "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//
//Input: "abcd"
//Output: "dcbabcd"
//


// solution I：求最长回文前缀
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        
        int n = s.size();
        int i = 0;
        for (i = n; i >= 0; --i)
        {
            if (r.substr(n-i) == s.substr(0, i))
                break;
        }
        
        return r.substr(0, n - i) + s;
    }
};


// solution II：KMP
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty())
            return s;
            
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "$" + r;
        
        int next[t.size()] = {0};
        next[0] = -1;
        int i = 0;
        int j = -1;
        while (i < t.size() - 1)
        {
            if (j == -1 || t[i] == t[j])
                next[++i] = ++j;
            else
                j = next[j];
        }
    
        return r.substr(0, s.size() - next[t.size() - 1] - 1) + s;
    }
};

