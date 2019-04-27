// Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

// Note:

// An integer point is a point that has integer coordinates. 
// A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
// ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
// length and width of each rectangle does not exceed 2000.
// 1 <= rects.length <= 100
// pick return a point as an array of integer coordinates [p_x, p_y]
// pick is called at most 10000 times.
// Example 1:

// Input: 
// ["Solution","pick","pick","pick"]
// [[[[1,1,5,5]]],[],[],[]]
// Output: 
// [null,[4,1],[4,1],[3,3]]
// Example 2:

// Input: 
// ["Solution","pick","pick","pick","pick","pick"]
// [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
// Output: 
// [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
// Explanation of Input Syntax:

// The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.


class Solution {
public:
    Solution(vector<vector<int>> rects) {
        _rects = rects;
        _totalArea = 0;
        // 记录总面积和各个矩形的面积及其位置的映射关系
        for (auto rect : rects) 
        {
            _totalArea += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            _areaToIdx.insert({_totalArea, _areaToIdx.size()});
        }
    }
    
    vector<int> pick() {
        int val = rand() % _totalArea; // 按照面积随机选取一个位置
        int idx = _areaToIdx.upper_bound(val)->second; // 这里的upper_bound不可能是end
        int width = _rects[idx][2] - _rects[idx][0] + 1;
        int height = _rects[idx][3] - _rects[idx][1] + 1;
        
        return {rand() % width + _rects[idx][0], rand() % height + _rects[idx][1]}; // 在矩形内再随机选个位置
    }

private:
    vector<vector<int>> _rects;
    int _totalArea;
    map<int, int> _areaToIdx;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */