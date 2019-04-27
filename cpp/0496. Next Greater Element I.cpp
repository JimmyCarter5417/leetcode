// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]
// Explanation:
//     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
//     For number 1 in the first array, the next greater number for it in the second array is 3.
//     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4].
// Output: [3,-1]
// Explanation:
//     For number 2 in the first array, the next greater number for it in the second array is 3.
//     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
// Note:
// All elements in nums1 and nums2 are unique.
// The length of both nums1 and nums2 would not exceed 1000.


// 关键在于findNums不重复
// 相似的问题：503 556 739
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m; // 记录右侧第一个大值
        stack<int> stk; // 单调递减栈
        
        for (int n: nums) // 从前往后遍历
        {
            while (!stk.empty() && stk.top() < n)
            {
                m[stk.top()] = n; // 出栈，记录令其出栈的数字
                stk.pop();
            }
            
            stk.push(n);
        }
        
        for (int n: findNums)
        {
            if (m.count(n))
            {
                res.push_back(m[n]);
            }
            else
            {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};