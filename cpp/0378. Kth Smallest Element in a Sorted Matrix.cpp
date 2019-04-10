// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// Example:

// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,

// return 13.
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ n2.
    



// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85173/Share-my-thoughts-and-Clean-Java-Code

// solution I: 最小堆
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
        {
            return -1;
        }
        
        auto cmp = [&](const pair<int, int>& p1, const pair<int, int>& p2)
                   {
                       return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
                   };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); // 注意这种最小堆的定义方法
        
        for (int i = 0; i < matrix.size(); i++) // 先把第一行压入堆
        {
            pq.push({0, i}); 
        }
        
        for (int i = 0; i < k - 1; i++) // 总共循环k - 1次，每次都会弹出一个最小值，并“有可能”压入弹出数字的正下方数字
        {
            const pair<int, int> t = pq.top();
            pq.pop();
            
            if (t.first < matrix.size() - 1)
            {
                pq.push({t.first + 1, t.second});
            }
        }
        
        return matrix[pq.top().first][pq.top().second]; // 前k - 1次弹出最小值，此时的堆顶最小值就是kth smallest
    }    
};

// solution II: 二分法
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1]; 
        
        while (left < right)
        {
            int mid = left + (right - left) / 2;            
            int cnt = count(matrix, mid);
            
            if (cnt < k) // k比较大，此处不能有等于
            {
                left = mid + 1;
            }
            else // k比较小
            {
                right = mid;
            }
        }
        
        return left;
    }
    
    // 查找小于等于mid的总个数
    int count(const vector<vector<int>>& matrix, int mid)
    {
        int cnt = 0;
        int n = matrix.size();
        
        for (int i = 0; i < n; i++)
        {
            int j;
            for (j = 0; j < n; j++)
            {
                if (matrix[i][j] > mid)
                {
                    break;
                }
            }

            cnt += j;
        }

        return cnt;
    }     
};
