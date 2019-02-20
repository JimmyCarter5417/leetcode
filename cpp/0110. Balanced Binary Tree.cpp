// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example 1:

// Given the following tree [3,9,20,null,null,15,7]:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.

// Example 2:

// Given the following tree [1,2,2,3,3,null,null,4,4]:

//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
    
    int check(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        
        int leftDepth = check(root->left);
        if (leftDepth == -1) // 提前判断可减少递归深度
        {
            return -1;
        }
        
        int rightDepth = check(root->right);
        if (rightDepth == -1)
        {
            return -1;
        }        
        
        if (abs(leftDepth - rightDepth) > 1)
        {
            return -1;
        }
        
        return max(rightDepth, leftDepth) + 1;
    }
};