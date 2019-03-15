// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
// Example:

// MyQueue queue = new MyQueue();

// queue.push(1);
// queue.push(2);  
// queue.peek();  // returns 1
// queue.pop();   // returns 1
// queue.empty(); // returns false
// Notes:

// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
// solution I: 利用辅助栈    
//         stack<int> tmp;
        
//         while (!stk.empty())
//         {
//             tmp.push(stk.top());
//             stk.pop();
//         }
        
//         stk.push(x);
        
//         while (!tmp.empty())
//         {
//             stk.push(tmp.top());
//             tmp.pop();
//         }
    
// solution II: 利用函数调用栈    
        if (stk.empty())
        {
            stk.push(x);
            return;
        }
        
        int t = stk.top();
        stk.pop();
        this->push(x);
        stk.push(t);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = stk.top();
        stk.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
    
    stack<int> stk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
