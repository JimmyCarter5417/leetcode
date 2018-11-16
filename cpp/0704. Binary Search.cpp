// Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
 

// Note:

// You may assume that all elements in nums are unique.
// n will be in the range [1, 10000].
// The value of each element in nums will be in the range [-9999, 9999].

// 查找是否存在
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        
        return -1;
    }
};

// 查找第一个
int searchFirst(vector<int>& nums, int target)
{
      int left = 0;
      int right = nums.size() - 1;
      while (left < right)
      {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target)
                  left = mid + 1;                  
            else                
                  right = mid;//如果上一句求mid也写成int mid = left + (right - left + 1) / 2;会导致只有两个数字时right无法更新                  
      }

      if (nums[left] == target)
            return left;
      else
            return -1;
}

// 查找最后一个
int searchLast (vector<int>& nums, int target)
{
      int left = 0;
      int right = nums.size() - 1;
      while (left < right)
      {
            int mid = left + (right - left + 1) / 2;

            if (nums[mid] <= target)
                  left = mid;//上面+1就是为了防止只有两个数字时left无法更新，+1使得mid取两个数字的后一个
            else
                  right = mid - 1;
      }

      if (nums[left] == target)
            return left;
      else
            return -1;
}