// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

// Example 1:
// Input: [3, 2, 1]

// Output: 1

// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]

// Output: 2

// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:
// Input: [2, 2, 3, 1]

// Output: 1

// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long val1 = LLONG_MIN; // 防止非法的INT_MAX
        long long val2 = LLONG_MIN;
        long long val3 = LLONG_MIN;
        
        for (auto& num: nums)
        {
            // 一定要处理这种相同的情况，1如223
            if (num == val1 || num == val2 || num == val3)
            {
                continue;
            }
                
            if (num > val1)
            {
                val3 = val2;
                val2 = val1;
                val1 = num;
            }
            else if (num > val2)
            {
                val3 = val2;
                val2 = num;
            }
            else if (num > val3)
            {
                val3 = num;
            }
        }
        
        return val3 == LLONG_MIN ? val1 : val3;
    }
};
