// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

// Example 1:

// Input:
// s = "aaabb", k = 3

// Output:
// 3

// The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:

// Input:
// s = "ababbc", k = 2

// Output:
// 5

// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.


class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int n = s.size();
        int start = 0;
        
        while (start + k < n)
        {
            int m[26] = {0};
            int flag = 0;
            int end = start + 1; // 这里end默认要取下一位置，因为有可能for循环没有更新end
            
            for (int i = start; i < n; ++i)
            {
                int pos = s[i] - 'a';
                if (++m[pos] < k)
                    flag |= (1<<pos); // 个数小于k，置位
                else
                    flag &= (~(1<<pos)); // 个数大于k，复位
                    
                if (flag == 0) // 为0，表示全部大于k
                {
                    end = i + 1; // end要取下一个位置
                    res = max(res, end - start);
                }
            }
            
            start = end; // 用新的end更新start
        }
        
        return res;
    }
};