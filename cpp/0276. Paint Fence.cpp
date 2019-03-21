// There is a fence with n posts, each post can be painted with one of the k colors.

// You have to paint all the posts such that no more than two adjacent fence posts have the same color.

// Return the total number of ways you can paint the fence.

// Note:
// n and k are non-negative integers.


// 与偷房子问题有点类似
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) 
            return 0;
            
        int same = 0;
        int diff = k;
        
        for (int i = 2; i <= n; ++i) 
        {
            int t = diff;
            diff = (same + diff) * (k - 1); // 要么和前两个颜色相同，要么不同，但i和i-1必定异色
            same = t;
        }
        
        return same + diff; // 同色异色之和
    }
};
