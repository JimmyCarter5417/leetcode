// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
// The update(i, val) function modifies nums by updating the element at index i to val.

// Example:
// Given nums = [1, 3, 5]
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8

// Note:
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.


// 树状数组

// C1 = A1
// C2 = A1 + A2
// C3 = A3
// C4 = A1 + A2 + A3 + A4
// C5 = A5
// C6 = A5 + A6
// C7 = A7
// C8 = A1 + A2 + A3 + A4 + A5 + A6 + A7 + A8

// 坐标            二进制         最低位
// 1               0001          1
// 2               0010          2
// 3               0011          1
// 4               0100          4
// 5               0101          1
// 6               0110          2
// 7               0111          1
// 8               1000          8
class NumArray {
public:
    NumArray(vector<int>& nums) {
        // 1为起始索引
        num.resize(nums.size() + 1);
        bit.resize(nums.size() + 1);
        
        for (int i = 0; i < nums.size(); i++)
        {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - num[i + 1]; // 1为起始索引
        // 下一个更新的数字；对奇数来说，就是下一个偶数，对偶数来说，是后面“某个偶数”
        for (int j = i + 1; j < num.size(); j += (j&-j)) 
        {
            bit[j] += diff;
        }
        
        num[i + 1] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);   
    }
    
private:
    int getSum(int i)
    {
        int res = 0;
        
        // 下一个要加数字：对于奇数来说，就是前面一个偶数；对于偶数来说，是前面“某个偶数”
        for (int j = i; j >= 1; j -= (j&-j))
        {
            res += bit[j];
        }
        
        return res;
    }
    
    vector<int> num;
    vector<int> bit;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */