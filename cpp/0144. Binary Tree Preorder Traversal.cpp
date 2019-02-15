// Given a binary tree, return the preorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,2,3]
// Follow up: Recursive solution is trivial, could you do it iteratively?


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // solution I: recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
    void preorder(TreeNode* root, vector<int>& res)
    {
        if (root)
        {
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }
};

// solution II: iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
        {
            return {};
        }
        
        vector<int> res;
        stack<TreeNode*> stk;
        
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode* p = stk.top();
            stk.pop();
            
            res.push_back(p->val);
            if (p->right)
            {
                stk.push(p->right);
            }
            if (p->left)
            {
                stk.push(p->left);
            }            
        }
        
        return res;
    }
};
