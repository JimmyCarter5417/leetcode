// You are given a binary tree in which each node contains an integer value.
// Find the number of paths that sum to a given value.
// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

// Example:

// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

// Return 3. The paths that sum to 8 are:

// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11


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
    // 以root为根节点，sum为目的数字
    int pathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return 0;
        }

        // 前序遍历
        // 对于根节点不能简单判断roo->val == sum，还有处理子节点，这就是sumUp的作用
        return sumUp(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    // 以root为根节点，left为剩余数字，路径上所有符合条件的结果
    int sumUp(TreeNode* root, int left)
    {
        if (!root)
        {
            return 0;
        }    
      
        return (root->val == left) + sumUp(root->left, left - root->val) + sumUp(root->right, left - root->val);
    }
};