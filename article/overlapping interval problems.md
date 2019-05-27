# overlapping interval problem

Here I provide a concise template that I summarized for the so-called "Overlapping Interval Problem".  

[Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)   
[Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals)   
[Merge Intervals](https://leetcode.com/problems/merge-intervals)   
[Meeting Rooms](https://leetcode.com/problems/meeting-rooms/)   
[Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)  

I found these problems share some similarities on their solutions.

* Sort intervals/pairs in increasing order of the start position.  
* Scan the sorted intervals, and maintain an ***active set*** for overlapping intervals. At most times, we do not need to use an explicit set to store them. Instead, we just need to maintain several key parameters, e.g. the number of overlapping intervals (count), the minimum ending point among all overlapping intervals (minEnd).  
* If the interval that we are currently checking overlaps with the ***active set***, which can be characterized by cur.start > minEnd, we need to renew those key parameters or change some states.  
* If the current interval does not overlap with the ***active set***, we just drop current ***active set***, record some parameters, and create a new ***active set*** that contains the current interval.

```
int count = 0; // Global parameters that are useful for results.  
int minEnd = INT_MAX; // Key parameters characterizing the active set for overlapping intervals, e.g. the minimum ending point among all overlapping intervals.
sort(points.begin(), points.end()); // Sorting the intervals/pairs in ascending order of its starting point
for each interval 
{
    if(interval.start > minEnd) // If the interval overlaps with the active set
    { 
        // changing some states, record some information, and start a new active set. 
        count++;
        minEnd = p.second;
    }
    else 
    {
        // renew key parameters of the active set
        minEnd = min(minEnd, p.second);
    } 
}
return the result recorded in or calculated from the global information;
```

For example, for the problem [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/), we have:     

* Sort balloons in increasing order of the start position. 
* Scan the sorted pairs, and maintain a pointer for the minimum end position for current "active balloons", whose diameters are overlapping. 
* When the next balloon starts after all active balloons, shoot an arrow to burst all active balloons, and start to record next active balloons. 

```
int findMinArrowShots(vector<pair<int, int>>& points) {
    int count = 0, minEnd = INT_MAX;
    sort(points.begin(), points.end());
    for(auto& p: points) 
    {
        if(p.first > minEnd) 
        {
            count++; 
            minEnd = p.second;
        }
        else 
        {
            minEnd = min(minEnd, p.second);
        }
    }
    return count + !points.empty();
}
```

For the problem [Non-overlapping Intervals](https://github.com/wangqiang5417/leetcode/blob/master/cpp/0435.%20Non-overlapping%20Intervals.cpp), we have:  
```
int eraseOverlapIntervals(vector<Interval>& intervals) {
    int total = 0, minEnd = INT_MIN, overNb = 1;
    sort(intervals.begin(), intervals.end(), 
        [&](Interval& inter1, Interval& inter2) 
        {
            return inter1.start < inter2.start;
        });
    for(auto& p: intervals) 
    {
        if(p.start >= minEnd) 
        {
            total += overNb-1;
            overNb = 1;
            minEnd = p.end;
        }
        else 
        {
            overNb++;
            minEnd = min(minEnd, p.end);
        }
    }
    return total + overNb-1;
}
```

