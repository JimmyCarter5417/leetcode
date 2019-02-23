//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//Your algorithm should run in O(n) complexity.
//
//Example:
//
//Input: [100, 4, 200, 1, 3, 2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        for (int n: nums)
        {
            if (s.find(n) != s.end()) // 由于会删除哈希的数字，可能会找不到
            {
                // 找到前后边界
                int prev = n - 1;
                int next = n + 1;
                
                while (s.find(prev) != s.end())
                {
                    s.erase(prev);
                    prev--;
                }
                while (s.find(next) != s.end())
                {
                    s.erase(next);
                    next++;
                }
                
                res = max(res, next - prev - 1);
            }
        }
        
        return res;
    }
};

