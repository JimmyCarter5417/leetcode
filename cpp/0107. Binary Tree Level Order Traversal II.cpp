// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        if (!root)
        {
            return {};
        }
        
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> line;
            
            for (int i = 0; i < n; i++)
            {
                TreeNode* p = q.front();                
                q.pop();
                
                line.push_back(p->val);
                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            
            res.push_back(line);
        }
        
        reverse(res.begin(), res.end()); // 多个翻转即可
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        
        dfs(root, 0, res);
        reverse(res.begin(), res.end()); // 多个翻转即可
        return res;
    }
    
    void dfs(TreeNode* root, int level, vector<vector<int>>& res)
    {        
        if (level == res.size())
        {
            res.push_back({});
        }
        
        res[level].push_back(root->val);        
        if (root->left)
        {
            dfs(root->left, level + 1, res);
        }
        if (root->right)
        {
            dfs(root->right, level + 1, res);
        }
    }
};