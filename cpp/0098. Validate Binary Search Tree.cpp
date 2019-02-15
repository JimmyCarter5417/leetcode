// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:

// Input:
//     2
//    / \
//   1   3
// Output: true
// Example 2:

//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
//              is 5 but its right child's value is 4.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // solution I：递归
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    // 关键是带入最大最小值
    bool isValidBST(TreeNode* root, long mn, long mx)
    {
        if (!root)
        {
            return true;
        }
        
        if (root->val <= mn && root->val >= mx)
        {
            return false;
        }
        
        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
    }
};

// solution II：中序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> out;
        inorder(root, out);
        // BST中序遍历是递增的（本题不考虑相等）
        for (int i = 1; i < out.size(); i++)
        {
            if (out[i - 1] >= out[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void inorder(TreeNode* root, vector<int>& out)
    {
        if (root)
        {
            inorder(root->left, out);   
            out.push_back(root->val);
            inorder(root->right, out);
        }        
    }
};
