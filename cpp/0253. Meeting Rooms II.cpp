
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.


// solution I: 按照起始结束时间计数
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto a : intervals) 
        {
            ++m[a.start];
            --m[a.end];
        }
        
        int rooms = 0, res = 0;
        for (auto it : m) 
        {
            rooms += it.second;
            res = max(res, rooms);
        }
        
        return res;
    }
};

// solution II: 最小堆
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [](const Interval &a, const Interval &b)
             {
                return a.start < b.start;
             });
             
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto a : intervals) 
        {
            if (!q.empty() && q.top() <= a.start) 
            {
                q.pop();
            }
            
            q.push(a.end);
        }
        
        return q.size();
    }
};
