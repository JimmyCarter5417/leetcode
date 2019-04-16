// A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

// For example, these are arithmetic sequence:

// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.

// 1, 1, 2, 5, 7

// A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

// A slice (P, Q) of array A is called arithmetic if the sequence:
// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

// The function should return the number of arithmetic slices in the array A.


// Example:

// A = [1, 2, 3, 4]

// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.




// https://leetcode.com/articles/arithmetic-slices/#approach-1-brute-force-accepted
// solution I: 递归
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0; // 记录总共的分片个数
        
        fun(A, A.size() - 1, cnt);        
        
        return cnt;
    }
    
    int fun(const vector<int>& A, int end, int& cnt)
    {
        if (end <= 1)
        {
            return 0;
        }
        
        int res = 0; // 记录以end为终点的切片个数
        
        if (A[end] - A[end - 1] == A[end - 1] - A[end - 2])
        {
            res = fun(A, end - 1, cnt) + 1; // 最后一个新增的数字符合等差条件，则res就是上一位置的结果+1，如123[4]，多了一个234
            cnt += res; // 总共的cnt要加上当前end的结果           
        }
        else
        {
            fun(A, end - 1, cnt); // 当前end不能成为等差数组的结尾，res当然是0，也不需要增加cnt，但还是要继续递归
        }
        
        return res;
    }
};

// solution II: 动态规划
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty())
        {
            return 0;
        }
            
        int res = 0;
        int n = A.size();
        int dp[n] = {0}; // dp[i]表示以i为末尾的等差数组个数
        
        for (int i = 2; i < n; ++i)
        {
            if (A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                dp[i] = dp[i-1] + 1; // 与递归的思想类似，123[4]，多了一个234
            }
            
            res += dp[i]; // 与递归的思想类似，这里要将所有的dp结果相加
        }
        
        return res;
    }
};
