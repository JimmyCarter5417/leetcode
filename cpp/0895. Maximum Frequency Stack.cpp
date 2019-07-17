// Implement FreqStack, a class which simulates the operation of a stack-like data structure.

// FreqStack has two functions:
// push(int x), which pushes an integer x onto the stack.
// pop(), which removes and returns the most frequent element in the stack.
// If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 
// Example 1:
// Input: 
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
// [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
// Output: [null,null,null,null,null,null,null,5,7,5,4]
// Explanation:
// After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:
// pop() -> returns 5, as 5 is the most frequent.
// The stack becomes [5,7,5,7,4].
// pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
// The stack becomes [5,7,5,4].
// pop() -> returns 5.
// The stack becomes [5,7,4].
// pop() -> returns 4.
// The stack becomes [5,7]. 

// Note:
// Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
// It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
// The total number of FreqStack.push calls will not exceed 10000 in a single test case.
// The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
// The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.


class FreqStack {
public:
    FreqStack() {
        maxFreq_ = 0;
    }
    
    void push(int x) {
        ++freq_[x]; // 记录x的频率
        maxFreq_ = max(maxFreq_, freq_[x]); // 记录最大频率
        stk_[freq_[x]].push_back(x); // 将“x”加入其频率所属的“栈帧”尾部
    }
    
    int pop() {        
        int x = stk_[maxFreq_].back(); // 最大频率栈帧尾部数字，即为要弹出的元素
        stk_[maxFreq_].pop_back(); // 弹出
        freq_[x]--; // 弹出数字的频率减一
        if (stk_[maxFreq_].empty()) // 弹出后，最大频率栈帧为空，要向下移动栈帧
        {
            maxFreq_--; // 类似于改变sp寄存器，退栈
        }
        
        return x;
    }
    
    int maxFreq_; // 记录所有数字出现的最大频率，类似于sp寄存器
    unordered_map<int, int> freq_; // x : freq，记录某个数字出现的最大频率，主要为了维护maxFreq_
    unordered_map<int, vector<int>> stk_; // freq : x1,x2,x3...记录某个频率包含的数字，相当于栈帧的集合，就是栈，注意：一个数字会出现在其最大频率及以下的所有频率的栈帧中
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
