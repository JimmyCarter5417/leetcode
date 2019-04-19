// Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

// Note:
// Both the string's length and k will not exceed 104.

// Example 1:
// Input:
// s = "ABAB", k = 2
// Output:
// 4
// Explanation:
// Replace the two 'A's with two 'B's or vice versa.

// Example 2:
// Input:
// s = "AABABBA", k = 1
// Output:
// 4
// Explanation:
// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.


// 滑动窗口模型，与159 340相同
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int start = 0;
        int mx = 0;
        unordered_map<char, int> m; // 记录窗口内每个字符出现的次数
        
        for (int i = 0; i < s.size(); i++)
        {
            mx = max(mx, ++m[s[i]]); // i位置进入窗口
            
            while (i - start + 1 > k + mx) // 窗口大小一旦大于“最多的字符+可替换的字符”总个数，就要右移start，目的是为了减小窗口内字符的计数
            {
                m[s[start]]--; // start位置离开窗口
                start++;
            }
            
            res = max(res, i - start + 1); // res即为窗口的最大尺寸
        }
        
        return res;
    }
};
