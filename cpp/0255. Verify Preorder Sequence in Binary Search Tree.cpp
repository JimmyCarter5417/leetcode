// Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

// You may assume each number in the sequence is unique.

// Follow up:
// Could you do it using only constant space complexity?


// good issue! 
// solution I: 分治法，与Validate Binary Search Tree类似
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
    }
    
    // 利用上下界进行检测
    bool helper(vector<int> &preorder, int start, int end, int lower, int upper) {
        if (start > end) return true;
        int val = preorder[start], i = 0;
        if (val <= lower || val >= upper) return false;
        for (i = start + 1; i <= end; ++i) {
            if (preorder[i] >= val) break; // 找到右子节点
        }
        return helper(preorder, start + 1, i - 1, lower, val) && helper(preorder, i, end, val, upper);
    }
};

//     5
//    / \
//   2   6
//  / \
// 1   3
// solution II: 栈
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> s;
        for (auto a : preorder) {
            if (a < low) return false; // 非法
            while (!s.empty() && a > s.top()) { // 维护单调递减栈
                low = s.top(); // 维护最小值，保存弹出的最后一个数字
                s.pop(); 
            }
            s.push(a);
        }
        return true;
    }
};
