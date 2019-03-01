// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// Example:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

// Output: ["AAAAACCCCC", "CCCCCAAAAA"]


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10)
        {
            return {};
        }
        
        vector<string> res;
        unordered_map<int, int> m;
        int cur = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (i < 9) // 第一阶段：计算窗口编码
            {
                cur = ((cur << 3) | (s[i] & 0x7));
            }
            else // 第二阶段：更新窗口编码
            {                
                cur = (((cur & 0x7ffffff) << 3) | (s[i] & 0x7));            
                               
                if (++m[cur] == 2)
                {
                    res.push_back(s.substr(i - 9, 10));
                }
            }
        }
        
        return res;
    }
};
