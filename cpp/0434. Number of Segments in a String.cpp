// Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

// Please note that the string does not contain any non-printable characters.

// Example:

// Input: "Hello, my name is John"
// Output: 5


class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        istringstream iss(s);
        string t;

        while (getline(iss, t, ' '))
        {
            if (!t.empty())
            {
                ++res;
            }
        }
        
        return res;
    }
};