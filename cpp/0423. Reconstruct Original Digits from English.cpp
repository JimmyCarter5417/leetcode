// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

// Note:
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
// Example 1:
// Input: "owoztneoer"

// Output: "012"
// Example 2:
// Input: "fviefuro"

// Output: "45"


class Solution {
public:
    string originalDigits(string s) {
        string res;
        unordered_map<char, int> m;
        int cnt[10] = {0};
        
        for (char ch: s)
        {
            m[ch]++;
        }
        
        // 独占的字符
        cnt[0] = m['z'];
        cnt[2] = m['w'];
        cnt[4] = m['u'];
        cnt[6] = m['x'];
        cnt[8] = m['g'];
        // 共享的字符，减去上面几个独占的字符个数即可
        cnt[1] = m['o'] - cnt[0] - cnt[2] - cnt[4];
        cnt[3] = m['h'] - cnt[8];
        cnt[5] = m['f'] - cnt[4];
        cnt[7] = m['v'] - cnt[5];
        cnt[9] = m['i'] - cnt[5] - cnt[6] - cnt[8];
        
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                res += to_string(i);
            }
        }
        
        return res;
    }
};
