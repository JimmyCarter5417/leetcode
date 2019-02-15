// iven a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 左右递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* p1, TreeNode* p2)
    {
        if (!p1 && !p2)
        {
            return true;
        }
        
        if ((p1 && !p2) || (!p1 && p2) || (p1->val != p2->val))
        {
            return false;
        }
        
        return isSymmetric(p1->left, p2->right) && isSymmetric(p1->right, p2->left);
    }
};
