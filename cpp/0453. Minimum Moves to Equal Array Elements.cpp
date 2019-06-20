// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

// Example:
// Input:
// [1,2,3]
// Output:
// 3
// Explanation:
// Only three moves are needed (remember each move increments two elements):
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;        
        for (int n: nums)
        {
            minNum = min(minNum, n);
        }
        
        // 选n-1个数字加1，等效于选1个数字减1，进而转换成求所有数字与最小值的差的总和
        // 很巧妙！
        int res = 0;
        for (int n: nums)
        {
            res += n - minNum;
        }    
            
        return res;
    }
};