//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(const vector<int>& preorder, int preStart, int preEnd, 
                     const vector<int>& inorder,  int inStart,  int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }
        
        int i;
        for (i = inStart; i <= inEnd; i++)
        {
            if (inorder[i] == preorder[preStart])
            {
                break;
            }
        }
        
        TreeNode* res = new TreeNode(preorder[preStart]);
        res->left  = helper(preorder, preStart + 1,               preStart + i - inStart, inorder, inStart, i - 1);
        res->right = helper(preorder, preStart + i - inStart + 1, preEnd,                 inorder, i + 1,   inEnd);
        return res;
    }
};

