给一个数组，返回一个大小相同的数组。  
返回的数组的第i个位置的值应当是，对于原数组中的第i个元素，至少往右走多少步，才能遇到一个比自己大的元素。  
如果之后没有比自己大的元素，或者已经是最后一个元素，则在返回数组的对应位置放上-1）。

```
vector<int> nextExceed(vector<int> &input) {
	vector<int> result (input.size(), -1);
	stack<int> monoStack;
	for(int i = 0; i < input.size(); ++i) {	
		while(!monoStack.empty() && input[monoStack.top()] < input[i]) {
			result[monoStack.top()] = i - monoStack.top();
			monoStack.pop();
		}
		monoStack.push(i);
	}
	return result;
}
```

[Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/#/description)  
```
int largestRectangleArea(vector<int> &height) {
    int ret = 0;
    height.push_back(0);
    vector<int> index;
    for(int i = 0; i < height.size(); i++) {
        while(index.size() > 0 && height[index.back()] >= height[i]) {
            int h = height[index.back()];
            index.pop_back();
            int sidx = index.size() > 0 ? index.back() : -1;
            ret = max(ret, h * (i-sidx-1));
        }
        index.push_back(i);
    }
    return ret;
}
```   

[Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)  
```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // 单调双向队列
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k) // 此处仅代表窗口达到最大值，需要强制弹出最前面的数字
            {
                // res.push_back(nums[dq.front()]); // 不能在此处添加
                dq.pop_front();
            }
            
            while (!dq.empty() && nums[dq.back()] < nums[i]) // 保证队列从前往后单调递减
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= k - 1) // 窗口长度之后，都要push_back，队列首部即为窗口最大值
            {
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};
```

similar problems:   
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/   
[Next Greater Element I](https://github.com/wangqiang5417/leetcode/blob/master/cpp/0496.%20Next%20Greater%20Element%20I.cpp)   
[Next Greater Element II](https://github.com/wangqiang5417/leetcode/blob/master/cpp/0503.%20Next%20Greater%20Element%20II.cpp)   
[Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)   
[Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)   