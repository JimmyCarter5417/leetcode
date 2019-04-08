// Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

// Return the sum of these numbers.

// Example 1:

// Input: [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 
// Note:

// The number of nodes in the tree is between 1 and 1000.
// node.val is 0 or 1.
// The answer will not exceed 2^31 - 1.


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
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
    
    int helper(TreeNode* root, int n)
    {
        if (!root)
        {
            return n;
        }
        
        n = n * 2 + root->val; // 对上面传下来的结果乘2，保证root most significant
        
        int n1 = helper(root->left, n);
        int n2 = helper(root->right, n);
        
        if (root->left && !root->right) // 注意分清是非是空指针，因为都有非0返回值
        {
            return n1;
        }
        else if (!root->left && root->right)
        {
            return n2;
        }
        else if (root->left && root->right)
        {
            return n1 + n2;
        }
        else 
        {
            return n;
        }
    }
};
