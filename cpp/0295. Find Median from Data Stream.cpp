// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

// For example,
// [2,3,4], the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Design a data structure that supports the following two operations:

// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
 

// Example:

// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
 

// Follow up:

// If all integer numbers from the stream are between 0 and 100, how would you optimize it?
// If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?


// a great problem!
// https://leetcode.com/articles/find-median-from-data-stream/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        
        if (lo.size() < hi.size()) // 保证lo大小不小于hi
        {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        int a = lo.empty() ? 0 : lo.top();
        int b = hi.empty() ? 0 : hi.top();
        
        if (lo.size() == hi.size())
        {
            return (a + b) / 2.0;
        }
        else
        {
            return a;
        }
    }
    
    priority_queue<int> lo; // 最大堆
    priority_queue<int, vector<int>, greater<int>> hi; // 最小堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

// Further Thoughts
// There are so many ways around this problem, that frankly, it is scary. Here are a few more that I came across:

// Buckets! If the numbers in the stream are statistically distributed, then it is easier to keep track of buckets where the median would land, than the entire array. Once you know the correct bucket, simply sort it find the median. If the bucket size is significantly smaller than the size of input processed, this results in huge time saving. @mitbbs8080 has an interesting implementation here.

// Reservoir Sampling. Following along the lines of using buckets: if the stream is statistically distributed, you can rely on Reservoir Sampling. Basically, if you could maintain just one good bucket (or reservoir) which could hold a representative sample of the entire stream, you could estimate the median of the entire stream from just this one bucket. This means good time and memory performance. Reservoir Sampling lets you do just that. Determining a "good" size for your reservoir? Now, that's a whole other challenge. A good explanation for this can be found in this StackOverflow answer.

// Segment Trees are a great data structure if you need to do a lot of insertions or a lot of read queries over a limited range of input values. They allow us to do all such operations fast and in roughly the same amount of time, always. The only problem is that they are far from trivial to implement. Take a look at my introductory article on Segment Trees if you are interested.

// Order Statistic Trees are data structures which seem to be tailor-made for this problem. They have all the nice features of a BST, but also let you find the kthorder element stored in the tree. They are a pain to implement and no standard interview would require you to code these up. But they are fun to use if they are already implemented in the language of your choice. [^note-5]
