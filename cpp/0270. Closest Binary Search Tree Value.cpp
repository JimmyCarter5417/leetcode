// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

// Note:

// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.


// solution I: 迭代，二分搜索
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;

        while (root) 
        {
            if (abs(res - target) >= abs(root->val - target)) 
            {
                res = root->val; // 二分搜索最接近的值
            }

            root = target < root->val ? root->left : root->right;
        }

        return res;
    }
};

// solution II: 递归
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        // 如果节点有非法值的话，可以在这里判断root是否为空，简化代码
        int a = root->val;

        TreeNode *t = target < a ? root->left : root->right;
        if (!t) 
            return a;
        
        int b = closestValue(t, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};
