//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9,3,15,20,7]
//postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* helper(const vector<int>& inorder,   int inStart,   int inEnd, 
                     const vector<int>& postorder, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
        {
            return NULL;
        }        
        
        int i;
        for (i = inStart; i <= inEnd; i++)
        {
            if (inorder[i] == postorder[postEnd])
            {
                break;
            }
        }        
        
        TreeNode* res = new TreeNode(postorder[postEnd]);
        res->left  = helper(inorder, inStart, i - 1, postorder, postStart,               postStart + i - inStart - 1);
        res->right = helper(inorder, i + 1,   inEnd, postorder, postStart + i - inStart, postEnd - 1);
        
        return res;
    }
};

