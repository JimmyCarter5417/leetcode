// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.


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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        
        if (root->left && !root->left->left && !root->left->right)
            return sumOfLeftLeaves(root->right) + root->left->val;
        else
            return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
    }
};

// solution II：迭代
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        
        while (p || !stk.empty())
        {
            while (p)
            {
                stk.push(p);
                p = p->left;
            }
            
            p = stk.top();
            stk.pop();
            
            // 只要计算“左叶子节点”即可
            if (p->left && !p->left->left && !p->left->right)
            {
                res += p->left->val;
            }
            
            p = p->right;
        }
        
        return res;
    }
};
