// Implement strStr().
//
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// Example 1:
//
// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:
//
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1


class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackSize = haystack.size();
        int needleSize = needle.size();
        if (needleSize == 0)
            return 0;
            
        // KMP
        // build next array
        int next[needleSize];
        next[0] = -1;
        int i = 0;
        int j = -1;
        while (i < needleSize - 1)
        {
            if (j == -1 || needle[i] == needle[j])
                next[++i] = ++j;
            else
                j = next[j];
        }
        
        // iterate
        i = 0;
        j = 0;
        while (i < haystackSize && j < needleSize)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        
        if (j == needleSize)
            return i - needleSize;
            
        return -1;// haystack.empty()
    }
};
