// Given a binary tree, count the number of uni-value subtrees.
// 
// A Uni-value subtree means all nodes of the subtree have the same value.
// 
// For example:
// Given binary tree,
// 
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// 
// return 4.


// solution I: 左右递归
class Solution {
public:
    int res = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return res;
        if (isUnival(root, root->val)) ++res;
        countUnivalSubtrees(root->left);
        countUnivalSubtrees(root->right);
        return res;
    }
    bool isUnival(TreeNode *root, int val, int& res) {
        if (!root) return true;
        return root->val == val && isUnival(root->left, val) && isUnival(root->right, val);
    }
}; 

// solution II: 减枝优化
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        isUnival(root, -1, res);
        return res;
    }
    bool isUnival(TreeNode* root, int val, int& res) {
        if (!root) return true;
        if (!isUnival(root->left, root->val, res) | !isUnival(root->right, root->val, res)) {
            return false;
        }
        ++res;
        return root->val == val;
    }
};
