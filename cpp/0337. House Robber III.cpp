// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:

// Input: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \ 
//      3   1

// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1

// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// solution I: naive TLE recursion
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) 
            return 0;

        int val = 0;
        if (root->left) 
        {
            val += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            val += rob(root->right->left) + rob(root->right->right);
        }
        // 要么选择root和两层以下，要么不选root选一层以下
        return max(val + root->val, rob(root->left) + rob(root->right));
    }
};

// solution II: 缓存优化
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m; // 增加缓存
        return dfs(root, m);
    }
    
    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& m)
    {
        if (!root)
        {
            return 0;
        }
        
        if (m.find(root) != m.end())
        {
            return m[root];
        }
        
        int val = 0;
        if (root->left)
        {
            val += dfs(root->left->left, m) + dfs(root->left->right, m);
        }
        if (root->right)
        {
            val += dfs(root->right->left, m) + dfs(root->right->right, m);
        }
        
        m[root] = max(root->val + val, dfs(root->left, m) + dfs(root->right, m));
        return m[root];
    }
};