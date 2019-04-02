// Design a hit counter which counts the number of hits received in the past 5 minutes.

// Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

// It is possible that several hits arrive roughly at the same time.

// Example:

// HitCounter counter = new HitCounter();

// // hit at timestamp 1.
// counter.hit(1);

// // hit at timestamp 2.
// counter.hit(2);

// // hit at timestamp 3.
// counter.hit(3);

// // get hits at timestamp 4, should return 3.
// counter.getHits(4);

// // hit at timestamp 300.
// counter.hit(300);

// // get hits at timestamp 300, should return 4.
// counter.getHits(300);

// // get hits at timestamp 301, should return 3.
// counter.getHits(301); 
// Follow up:
// What if the number of hits per second could be very large? Does your design scale?

// Credits:
// Special thanks to @elmirap for adding this problem and creating all test cases.


// solution I: 使用队列实现窗口功能
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {}
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= 300) 
        {
            q.pop();
        }

        return q.size();
    }

private:
    queue<int> q;
};

// solution II: 当hit很多的时候，可以节省空间
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        times.resize(300);
        hits.resize(300);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        // 本质上是用哈希表存储time和cnt
        int idx = timestamp % 300;

        if (times[idx] != timestamp) 
        {
            times[idx] = timestamp;
            hits[idx] = 1;
        } 
        else 
        {
            ++hits[idx];
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;

        for (int i = 0; i < 300; ++i) 
        {
            if (timestamp - times[i] < 300) 
            {
                res += hits[i];
            }
        }

        return res;
    }

private:
    vector<int> times, hits;
};