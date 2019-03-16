// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

// Example:

// Input:  [1,2,1,3,2,5]
// Output: [3,5]
// Note:

// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?


// Single Number的扩展
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff; // 取diff最右边为1的位
        
        for (int n: nums)
        {
            if (n&diff) // 利用diff的标志位将所有数字分组
            {
                res[0] ^= n;
            }
            else
            {
                res[1] ^= n;
            }
        }
        
        return res;
    }
};
