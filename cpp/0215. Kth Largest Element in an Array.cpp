//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Example 1:
//
//Input: [3,2,1,5,6,4] and k = 2
//Output: 5
//Example 2:
//
//Input: [3,2,3,1,2,4,5,5,6] and k = 4
//Output: 4
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ array's length.
//

// a greate issue!

// solution I: 利用STL的nth_element和partial_sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>()); // 第k个元素在应该在的位置，左边小右边大，类似bst
        // partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>()); // 只有前半段拍好序
        return nums[k - 1];
    }
};

// solution II: 最大堆
// time: O(N) + O(klgN)
// space: O(N)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        
        if (k > nums.size() || k < 0)
        {
            return -1;
        }
        
        // 建堆：O(N)
        for (int n: nums)
        {
            q.push(n);
        }
        // 出堆：O(klgN)
        while (--k)
        {
            q.pop();
        }
        
        return q.top();
    }
};

// solution III: 最小堆
// time: O(k) + O((N-k)lgk)
// space: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        if (k > nums.size() || k < 0)
        {
            return -1;
        }
        // 建堆：O(k)
        // 出堆：O((N-k)lgk)
        for (int n: nums)
        {
            if (q.size() == k)
            {
                if (n > q.top())
                {
                    q.pop();
                    q.push(n);
                }
            }
            else
            {
                q.push(n);
            }
        }        
        
        return q.top();
    }
};

// solution IV: 快速排序思想
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int kth;
        
        while (1)
        {
            int idx = partition(nums, left, right);
            
            if (idx == k - 1)
            {
                kth = nums[idx];
                break;
            }
            else if (idx < k - 1) 
            {
                left = idx + 1;
            } 
            else 
            {
                right = idx - 1;
            }
        }
        
        return kth;
    }
    
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left]; // pivot最好能随机化，对性能影响很大
        int l = left + 1;
        int r = right;
        
        while (l <= r) 
        {
            if (nums[l] < pivot && nums[r] > pivot) 
            {
                swap(nums[l++], nums[r--]);
            }
            
            if (nums[l] >= pivot) 
            {
                l++;
            }
            
            if (nums[r] <= pivot) 
            {
                r--;
            }
        }
        
        swap(nums[left], nums[r]);
        return r;
    }
};


