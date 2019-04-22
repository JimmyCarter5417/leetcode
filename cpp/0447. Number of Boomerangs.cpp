// Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

// Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

// Example:
// Input:
// [[0,0],[1,0],[2,0]]
// Output:
// 2

// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]


class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        
        for (auto& p: points)
        {
            unordered_map<int, int> mm;
            
            // 统计所有p点与其他点的距离
            for (auto& q: points)
            {
                int dx = p.first - q.first;
                int dy = p.second - q.second;
                mm[dx * dx + dy * dy]++;
            }
            
            // 相同距离的点可以组成所要找的结果
            for (auto& k: mm)
            {
                res += k.second * (k.second - 1); // 累加
            }
        }
        
        return res;
    }
};
