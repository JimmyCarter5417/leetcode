// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // solution I: dfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*, int>> stk; // 同时记录节点及其深度
        
        stk.push({root, 1});
        
        while (!stk.empty())
        {
            TreeNode* node = stk.top().first;
            int depth = stk.top().second;
            stk.pop();
            
            if (node) // 忽略空节点
            {
                if (depth > res.size()) // 达到新的深度，记录结果
                {
                    res.push_back(node->val);
                }
                // 入栈顺序先左后右，出栈才能先右后左
                stk.push({node->left, depth + 1});
                stk.push({node->right, depth + 1});
            }
        }
        
        return res;
    }
};

// solution II: bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
            
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            res.push_back(q.back()->val);
            
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* n = q.front();
                q.pop();
                
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }
        
        return res;
    }
};
