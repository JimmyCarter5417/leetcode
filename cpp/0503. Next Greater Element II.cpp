// Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

// Example 1:
// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number; 
// The second 1's next greater number needs to search circularly, which is also 2.

// Note: The length of given array won't exceed 10000.


// 相似的问题：496 556 739
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stk;
    
        // 从前往后遍历
        for (int i = 0; i < 2 * nums.size(); ++i) // 精髓：2 * size
        {
            int n = nums[i % nums.size()];
            
            while (!stk.empty() && nums[stk.top()] < n) // 栈内保存前面位置的递减栈
            {
                res[stk.top()] = n;
                stk.pop();
            }
            
            if (i < nums.size()) // i大于size，作用是循环遍历，不需要入栈，因为已经入过了
            {
                stk.push(i);
            }    
        }
        
        return res;
    }
};