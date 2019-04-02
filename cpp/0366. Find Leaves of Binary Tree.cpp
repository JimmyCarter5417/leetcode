// Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.

// Example:
// Given binary tree 

//           1
//          / \
//         2   3
//        / \     
//       4   5    
// Returns [4, 5, 3], [2], [1].

// Explanation:

// 1. Remove the leaves [4, 5, 3] from the tree

//           1
//          / 
//         2          
// 2. Remove the leaf [2] from the tree

//           1          
// 3. Remove the leaf [1] from the tree

//           []         
// Returns [4, 5, 3], [2], [1].

// Credits:
// Special thanks to @elmirap for adding this problem and creating all test cases.


// 与310. Minimum Height Trees类似，都可以用剥洋葱的方法实现

// solution I: 计算深度
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;

        helper(root, res);

        return res;
    }

    int helper(TreeNode *root, vector<vector<int>> &res) 
    {
        if (!root) 
            return -1;

        int depth = 1 + max(helper(root->left, res), helper(root->right, res));

        if (depth >= res.size()) 
            res.resize(depth + 1);

        res[depth].push_back(root->val);

        return depth;
    }
};

// solution II: 剥洋葱
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;

        while (root) 
        {
            vector<int> leaves;
            root = remove(root, leaves); // 并不是真正剥除节点，只是返回的时候效果相当于剥除

            res.push_back(leaves);
        }

        return res;
    }

    TreeNode* remove(TreeNode *node, vector<int> &leaves) 
    {                                                                                                            
        if (!node) 
            return NULL;

        if (!node->left && !node->right) 
        {
            leaves.push_back(node->val); // 保存node值
            return NULL;
        }

        node->left = remove(node->left, leaves);
        node->right = remove(node->right, leaves);

        return node;
    }
};