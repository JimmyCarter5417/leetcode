// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in this array.

// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

// Example:
// Input:
// [4,3,2,7,8,2,3,1]
// Output:
// [5,6]


// 与41. First Missing Positive相同的处理方法，利用1 ≤ a[i] ≤ n这条性质，在数组内重新排序
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        int cur = 0;
        while (cur < nums.size())
        {
            if (nums[cur] != cur + 1 && nums[cur] != nums[nums[cur] - 1]) 
            {
              // 把不在位置上的数字交换到应该在的位置，重复的数字会填充缺失的位置，如45331，重排后为13345
                swap(nums[cur], nums[nums[cur] - 1]); 
            }
            else
            {
                cur++;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1) // 数字与位置不匹配，即缺失该位置对应的数字
            {
                res.push_back(i + 1);
            }
        }
        
        return res;
    }
};
