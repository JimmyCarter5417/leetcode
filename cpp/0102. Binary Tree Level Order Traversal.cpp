// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]


// solution I：递归
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        fun(root, 0, res);
        return res;
    }

    void fun(TreeNode* root, int level, vector<vector<int>>& res)
    {
        if (root == nullptr)
            return ;

        if (res.size() == level)
            res.push_back({});

        res[level].push_back(root->val);
        fun(root->left, level + 1, res);
        fun(root->right, level + 1, res);
    }
};

// solution II：迭代
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = q.front();
                q.pop();

                level.push_back(cur->val);

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }

            res.push_back(level);
        }

        return res;
    }
};