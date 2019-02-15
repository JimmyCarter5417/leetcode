// Given a binary tree, return the postorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    void postorder(TreeNode* root, vector<int>& res)
    {
        if (root)
        {
            postorder(root->left, res);
            postorder(root->right, res);
            res.push_back(root->val);
        }
    }
};
 
 // solution II: iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
        {
            return {};
        }
        
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        
        TreeNode* pre = root;
        
        while (!s.empty())
        {
            TreeNode* p = s.top();
            
            if ((!p->left && !p->right) || p->right == pre || p->left == pre)
            {
                s.pop();
                res.push_back(p->val);
                pre = p;
            }
            else
            {
                if (p->right)
                {
                    s.push(p->right);
                }
                if (p->left)
                {
                    s.push(p->left);
                }
            }
            
        }
        
        return res;
    }
};
