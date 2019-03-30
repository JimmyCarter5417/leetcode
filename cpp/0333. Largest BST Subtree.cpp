// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

// Note:
// A subtree must include all of its descendants.
// Here's an example:

//     10
//     / \
//    5  15
//   / \   \ 
//  1   8   7
// The Largest BST Subtree in this case is the highlighted one. 
// The return value is the subtree's size, which is 3.

 

// Hint:

// You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
// Follow up:
// Can you figure out ways to solve it with O(n) time complexity?


// hard!
// solution I: 重复递归
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode *root, int &res) 
    {
        if (!root) 
            return;

        int d = countBFS(root, INT_MIN, INT_MAX);
        if (d != -1) 
        {
            res = max(res, d);
            return;
        }

        dfs(root->left, res);
        dfs(root->right, res);
    }

    int countBFS(TreeNode *root, int mn, int mx) 
    {
        if (!root) 
            return 0;

        if (root->val < mn || root->val > mx) 
            return -1;

        int left = countBFS(root->left, mn, root->val);
        if (left == -1) 
            return -1;

        int right = countBFS(root->right, root->val, mx);
        if (right == -1) 
            return -1;

        return left + right + 1;
    }
};

// solution II: O(N)
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        int mn = INT_MIN;
        int mx = INT_MAX;
        
        isValidBST(root, mn, mx, res);

        return res;
    }

    bool isValidBST(TreeNode *root, int &mn, int &mx, int &res) 
    {
        if (!root) 
            return true;

        int left_n   = 0,       right_n  = 0;
        int left_mn  = INT_MIN, left_mx  = INT_MAX;
        int right_mn = INT_MIN, right_mx = INT_MAX;

        bool left  = isValidBST(root->left,  left_mn,  left_mx,  left_n);
        bool right = isValidBST(root->right, right_mn, right_mx, right_n);

        if (left && right) 
        {
            if ((!root->left  || root->val >= left_mx) && 
                (!root->right || root->val <= right_mn)) 
            {
                res = left_n + right_n + 1;
                mn = root->left ? left_mn : root->val;
                mx = root->right ? right_mx : root->val;

                return true;
            }
        }

        res = max(left_n, right_n);
        return false;
    }
};