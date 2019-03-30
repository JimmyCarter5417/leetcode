// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

// For example,
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3


class MovingAverage {
public:
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        // 弹出最老的数字
        if (q.size() >= size) 
        {
            sum -= q.front(); 
            q.pop();
        }

        // 加入新数字
        q.push(val);
        sum += val;

        return sum / q.size();
    }
    
private:
    queue<int> q;
    int size;
    double sum;
};