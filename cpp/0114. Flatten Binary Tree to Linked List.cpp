//Given a binary tree, flatten it to a linked list in-place.
//
//For example, given the following tree:
//
//    1
//   / \
//  2   5
// / \   \
//3   4   6
//The flattened tree should look like:
//
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6


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
    void flatten(TreeNode* root) {
        if (!root)
        {
            return;
        }
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* pLeft = root->left;
        TreeNode* pRight = root->right;
        TreeNode* cur = pLeft;       
        
        if (!cur)
        {
            return;
        }
        // 右子树连到左子树末尾
        while (cur->right)
        {
            cur = cur->right;
        }
        
        cur->right = root->right;       
        root->right = root->left;
        root->left = NULL;
    }
};

