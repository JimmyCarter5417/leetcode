// Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

// For example:

// Given a binary tree {1,2,3,4,5},

//     1
//    / \
//   2   3
//  / \
// 4   5

// return the root of the binary tree [4,5,2,#,#,3,1].

//    4
//   / \
//  5   2
//     / \
//    3   1  


// Recursion
class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (!root || !root->left) return root;
        TreeNode *l = root->left, *r = root->right;
        TreeNode *res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};
