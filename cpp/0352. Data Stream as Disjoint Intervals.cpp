// Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

// For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

// [1, 1]
// [1, 1], [3, 3]
// [1, 1], [3, 3], [7, 7]
// [1, 3], [7, 7]
// [1, 3], [6, 7]
// Follow up:
// What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<Interval> res; // 需要新开辟一个临时数组
        Interval cur(val, val); // []
        int pos = 0;
        
        for (auto a: v) // ()
        {
            if (a.end < cur.start - 1) // ()-[]
            {
                res.push_back(a);
                pos++; // 记录前面插入了几个区间
            }
            else if (cur.end < a.start - 1) // []-()
            {
                res.push_back(a);
            }
            else if (a.end == cur.start - 1) // ()[]
            {
                cur.start = a.start;
            }
            else if (cur.end == a.start - 1) // []()
            {
                cur.end = a.end;
            }
            else // [(])或([)]
            {
                cur.start = min(cur.start, a.start);
                cur.end = max(cur.end, a.end);
            }
        }
        
        res.insert(res.begin() + pos, cur); // 把cur插入到合适位置
        v = res;
    }
    
    vector<Interval> getIntervals() {
        return v;
    }
    
private:
    vector<Interval> v;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<Interval> param_2 = obj->getIntervals();
 */