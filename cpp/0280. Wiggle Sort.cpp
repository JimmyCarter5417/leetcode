// Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

// For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].


// solution I: O(nlgn)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) 
            return;
        
        for (int i = 2; i < nums.size(); i += 2) 
        {
            swap(nums[i], nums[i - 1]); // 交换第二第三/第四第五/...
        }
    }
};

// solution I: O(n)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        if (nums.size() <= 1) 
            return;
            
        for (int i = 1; i < nums.size(); ++i) 
        {
            // 只需要保证相邻三个数字的单调属性即可
            // 当i为奇数时，nums[i] >= nums[i - 1]
            // 当i为偶数时，nums[i] <= nums[i - 1]
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || 
                (i % 2 == 0 && nums[i] > nums[i - 1])) 
            {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
