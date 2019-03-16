// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3


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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (NULL == root)
            return res;
        
        dfs(root, res, "");
        return res;
    }
    
    // 中序遍历最简单
    void dfs(TreeNode* root, vector<string>& res, string out)
    {
        out += to_string(root->val);
        
        if (NULL == root->left && NULL == root->right)
        {
            res.push_back(out);
            return;
        }
        else
        {
            out += "->";
            
            if (root->left)
                dfs(root->left, res, out);
                
            if (root->right)
                dfs(root->right, res, out);
        }
    }
};
