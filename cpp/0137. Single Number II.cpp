//Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
//Example 1:
//
//Input: [2,2,3,2]
//Output: 3
//Example 2:
//
//Input: [0,1,0,1,0,1,99]
//Output: 99
//


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        // 记录int每一位出现的次数，不是3的倍数即为所找的数拥有的位
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            
            for (int n: nums)
            {
                sum += ((n >> i) & 1);
            }
            
            res |= ((sum % 3) << i); // 还原该位
        }
        
        return res;
    }
};

