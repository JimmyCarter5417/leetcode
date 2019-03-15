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


// solution I: naive loop algorithm
class Solution {
public:
    int strStr(string haystack, string needle) { 
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        
        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            int j;
            
            for (j = 0; j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            
            if (j == needle.size())
            {
                return i;
            }
        }
        
        return -1;
    }
};

// solution II: KMP algorithm
class Solution {
public:
    int strStr(string haystack, string needle) { 
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        
        if (needle.empty())
        {
            return 0;
        }
        
        vector<int> next(needle.size());
        next[0] = -1; // next[0]一定是-1
        int i = 0;
        int j = -1;
        
        // 创建next数组，用needle的第i位推导第i+1位
        while (i < needle.size() - 1)
        {
            if (j == -1 || needle[i] == needle[j])
            {
                i++;
                j++;
                // 注意：此处如果不判断是否相同，仅next[i] = j，可能导致i处的next值比实际值大，匹配时会多几次处理
                if (needle[i] == needle[j])
                {
                    next[i] = next[j];
                }
                else
                {
                    next[i] = j;
                }
            }
            else
            {
                j = next[j];
            }
        }
        
        i = 0;
        j = 0;
        // 利用next数组遍历haystack
        while (i < (int)haystack.size() && j < (int)needle.size()) // 此处要注意有符号无符号的隐式转换，否则会出错
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }

        if (j == needle.size())
        {
            return i - needle.size();
        }
        else
        {
            return -1;
        }
    }
};
