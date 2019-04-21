// Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note:
// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
 
// Example 1:
// Input: [ [1,2], [2,3], [3,4], [1,3] ]
// Output: 1

// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 
// Example 2:
// Input: [ [1,2], [1,2], [1,2] ]
// Output: 2

// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

// Example 3:
// Input: [ [1,2], [2,3] ]
// Output: 0

// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
        {
            return 0;
        }
        
        int res = 0;
        int last = 0;
        
        sort(intervals.begin(), intervals.end()); // 先按照开始位置排序
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].front() < intervals[last].back()) // 有重叠
            {
                res++; // 需要删除一个
                
                if (intervals[i].back() < intervals[last].back()) // 注意：一定要取结束位置更小的区间，这样才能保证删除数目最少
                {
                    last = i;
                }
            }
            else
            {
                last = i; // 没有重叠也要更更新last
            }
        }
        
        return res;
    }
};