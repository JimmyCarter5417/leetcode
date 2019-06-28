// There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.
// An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

// Example:
// Input:
// [[10,16], [2,8], [1,6], [7,12]]
// Output:
// 2
// Explanation:
// One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {        
        sort(points.begin(), 
             points.end(), 
             [](const vector<int>& v1, const vector<int>& v2)
             {
                 if (v1[0] < v2[0])
                 {
                     return true;
                 }
                 else 
                 {
                     return v1[1] < v2[1]; // 这里为什么会导致越界访问？？？why？？？
                 }
             });
        
        int res = 0;
        int minEnd = INT_MIN;
        for (const vector<int>& point: points)
        {
            if (minEnd < point[0])
            {
                res++;
                minEnd = point[1];
            }
            else
            {
                minEnd = min(minEnd, point[1]);
            }
        }        
        
        return res;
    }
};