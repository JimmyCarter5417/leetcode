// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:
// Input:
// "tree"
// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:
// Input:
// "cccaaa"
// Output:
// "cccaaa"
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:
// Input:
// "Aabb"
// Output:
// "bbAa"
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

class Solution {
public:
    string frequencySort(string s) {
        string res;
        int m[256] = {0};
        auto cmp = [&](const pair<int, int>& p1, const pair<int, int>& p2)
                   {
                       return p1.second < p2.second;
                   };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp); // 最大堆，按照次数排序
        
        for (char ch: s)
        {
            m[ch]++;
        }
        
        for (int i = 0; i < 256; i++)
        {
            if (m[i] > 0)
            {
                q.push({i, m[i]});
            }
        }
        
        while (!q.empty())
        {
            pair<int, int> p = q.top();
            q.pop();
            
            for (int i = 0; i < p.second; i++)
            {
                res += p.first;
            }
        }
        
        return res;
    }
};
