// A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

// Example 1:
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
// Note:

// S will have length in range [1, 500].
// S will consist of lowercase letters ('a' to 'z') only.


class Solution {
public:
    vector<int> partitionLabels(string S) {
        // https://leetcode.com/articles/partition-labels/
        vector<int> res;
        int last[26];
        // 这个last数组很重要
        for (int i = 0; i < S.size(); i ++)
        {
            last[S[i] - 'a'] = i;
        }
        
        int start = 0;
        int end = 0;
        for (int i = 0; i < S.size(); i++)
        {
            end = max(end, last[S[i] - 'a']); // 关键在于更新end
            if (i == end)
            {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        
        return res;
    }
};
