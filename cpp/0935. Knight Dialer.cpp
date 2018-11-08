// A chess knight can move as indicated in the chess diagram below:

<div align=center><img src="https://github.com/wangqiang5417/leetcode/blob/master/pic/knight.png"/></div>         
<div align=center><img src="https://github.com/wangqiang5417/leetcode/blob/master/pic/keypad.png"/></div>    

// This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

// Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

// How many distinct numbers can you dial in this manner?

// Since the answer may be large, output the answer modulo 10^9 + 7.

 

// Example 1:

// Input: 1
// Output: 10
// Example 2:

// Input: 2
// Output: 20
// Example 3:

// Input: 3
// Output: 46
 

// Note:

// 1 <= N <= 5000


class Solution {
public:
    int knightDialer(int N) {
        // 使用自下而上的动态规划来处理
        vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        vector<int> d1(10, 1), d2(10);
        
        for (int i = 1; i < N; i++)
        {
            for (auto i = 0; i < d1.size(); ++i) 
            {
                d2[i] = accumulate(begin(ms[i]), end(ms[i]), 0, 
                                   [&](int s, int i) 
                                   {
                                       return (s + d1[i]) % 1000000007;
                                   });
            }
            
            swap(d1, d2);
        }
  
        return accumulate(begin(d1), end(d1), 0, [](int s, int n) {return (s + n) % 1000000007;});
    }
};
