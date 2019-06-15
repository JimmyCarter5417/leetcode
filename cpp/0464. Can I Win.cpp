// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.
// What if we change the game so that players cannot re-use integers?

// For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

// Example
// Input:
// maxChoosableInteger = 10
// desiredTotal = 11
// Output:
// false

// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.


// 与486. Predict the Winner类似
// 博弈论：与bash博弈类似，但数字只允许用一次，比较麻烦
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
            
        unordered_map<int, bool> m;
        return helper(maxChoosableInteger, desiredTotal, 0, m);
    }
    
    // used是一个bitmap，记录哪些数字被使用过
    bool helper(int len, int sum, int used, unordered_map<int, bool>& m)
    {
        if (m.find(used) != m.end())
            return m[used];
            
        // 因为len <= 20，才能这样做，否则位图要额外扩展范围
        for (int i = 1; i <= len; ++i)
        {
            int cur = (1<<(i - 1)); // cur代表第i个数在bitmap中的位置
            if ((cur & used) == 0) // 为0说明传入的used中，cur未被置位，即i未被使用过
            {
                // 这里要用i这个数了
                if (i >= sum || !helper(len, sum - i, used | cur, m)) // 将位图的i-1位置位，即位或运算cur
                {
                    m[used] = true;
                    return true;
                }
            }
        }
        
        m[used] = false;
        return false;
    }
};