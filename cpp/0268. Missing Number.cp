// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// Example 1:

// Input: [3,0,1]
// Output: 2
// Example 2:

// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8
// Note:
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?


// solution I: 利用异或的性质
class Solution {
public:
    int missingNumber(vector<int>& nums) {        
        int res = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            res ^= (i+1)^nums[i]; // 与single number类似
        }
        
        return res;
    }
};

// solution II: 排序法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 排序
        
        int left = 0;
        //int right = nums.size() - 1;
        int right = nums.size(); // 此处right必须是后一位，否则只有一个数字时会出错，如[0]
        int mid = 0;
        
        while (left < right) // 二分法
        {
            mid = (left + right) / 2;
             
            if (nums[mid] > mid)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        
        return right;
    }
};
