//In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
//
//We may rotate the i-th domino, so that A[i] and B[i] swap values.
//
//Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
//
//If it cannot be done, return -1.
//

//Example 1:
//Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
//Output: 2
//Explanation: 
//The first figure represents the dominoes as given by A and B: before we do any rotations.
//If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

//Example 2:
//Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
//Output: -1
//Explanation: 
//In this case, it is not possible to rotate the dominoes to make one row of values equal.
// 
//
//Note:
//
//1 <= A[i], B[i] <= 6
//2 <= A.length == B.length <= 20000
//


class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int top = A[0];
        int bot = B[0];
        int top1 = 0;
        int top2 = 0;
        int bot1 = 0;
        int bot2 = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (A[i] != top && B[i] != top) // 排除候选数字top
            {
                top = 0;
            }
            if (A[i] != bot && B[i] != bot) // 排除候选数字bot
            {
                bot = 0;
            }
            if (top == 0 && bot == 0) // 都为0，说明上下两个候选数字都被排除了，可提前结束
            {
                return -1;
            }
            
            if (A[i] == top)
            {
                top1++;
            }
            if (A[i] == bot)
            {
                top2++;
            }
            if (B[i] == top)
            {
                bot1++;
            }
            if (B[i] == bot)
            {
                bot2++;
            }
        }
        
        return n - max(max(top1, bot1), max(top2, bot2)); // 这里不用判断top、bot是否是0应该也可以，全部遍历的肯定比部分遍历的要大
    }
};

