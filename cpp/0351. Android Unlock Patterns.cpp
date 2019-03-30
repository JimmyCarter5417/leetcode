// Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

// Rules for a valid pattern:

// Each pattern must connect at least m keys and at most n keys.
// All the keys must be distinct.
// If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
// The order of keys used matters.
 
// Explanation:

// | 1 | 2 | 3 |
// | 4 | 5 | 6 |
// | 7 | 8 | 9 |
 

// Invalid move: 4 - 1 - 3 - 6 
// Line 1 - 3 passes through key 2 which had not been selected in the pattern.

// Invalid move: 4 - 1 - 9 - 2
// Line 1 - 9 passes through key 5 which had not been selected in the pattern.

// Valid move: 2 - 4 - 1 - 3 - 6
// Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

// Valid move: 6 - 5 - 4 - 1 - 9 - 2
// Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

// Example:
// Given m = 1, n = 1, return 9.

// Credits:
// Special thanks to @elmirap for adding this problem and creating all test cases.


class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int res = 0;
        vector<bool> visited(10, false);
        vector<vector<int>> jumps(10, vector<int>(10, 0));

        // 记录中间间隔的数字，相邻数字的中间间隔数字设为0
        jumps[1][3] = jumps[3][1] = 2;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = jumps[4][6] = jumps[6][4] = jumps[3][9] = jumps[9][3] = 5; 
        jumps[3][9] = jumps[9][3] = 6;
        jumps[7][9] = jumps[9][7] = 8;

        res += helper(1, 1, 0, m, n, jumps, visited) * 4; // 1 3 7 9
        res += helper(2, 1, 0, m, n, jumps, visited) * 4; // 2 4 6 8
        res += helper(5, 1, 0, m, n, jumps, visited);     // 5

        return res;
    }

    int helper(int num, int len, int res, int m, int n, vector<vector<int>> &jumps, vector<bool> &visited) 
    {
        if (len >= m) // 达到最小长度，开始计数
            ++res;

        ++len;

        if (len > n) // 达到最大长度，停止递归
            return res;

        visited[num] = true; // 记录访问标志
        for (int next = 1; next <= 9; ++next) 
        {
            int jump = jumps[num][next];
            if (!visited[next] && (jump == 0 || visited[jump])) // 只能访问一次，并且跳跃的数字必须已经访问过
            {
                res = helper(next, len, res, m, n, jumps, visited);
            }
        }
        visited[num] = false; // 恢复访问标志

        return res;
    }
}; 