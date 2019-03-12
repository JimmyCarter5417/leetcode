//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Example 1:
//
//Input: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//Output: 1
//Example 2:
//
//Input: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//Output: 3
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // solution I：迭代
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return -1;
        
        stack<TreeNode*> s;
        TreeNode* p = root;
        
        while (p || !s.empty())
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            
            p = s.top();
            s.pop();
            
            if (k == 1)
                return p->val;
            
            --k;
            p = p->right;
        }
        
        return -1;
    }
};

// solution II：递归
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return fun(root, k);
    }
    
    int fun(TreeNode* root, int& k)
    {
        if (NULL == root)
            return -1;
            
        int val = fun(root->left, k);
        
        if (0 == k)
            return val;
        
        if (1 == k--)
            return root->val;
            
        return fun(root->right, k);
        
    }
};

