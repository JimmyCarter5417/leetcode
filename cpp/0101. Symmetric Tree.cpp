// iven a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // solution I：左右递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* p1, TreeNode* p2)
    {
        if (!p1 && !p2)
        {
            return true;
        }
        
        if ((p1 && !p2) || (!p1 && p2) || (p1->val != p2->val))
        {
            return false;
        }
        
        return isSymmetric(p1->left, p2->right) && isSymmetric(p1->right, p2->left);
    }
};

// solution II：层序迭代
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> q1, q2;
        if (!root)
        {
            return false;
        }
        
        q1.push_back(root->left);
        q2.push_back(root->right);

        while (!q1.empty() && !q2.empty())
        {
            TreeNode* p1 = q1.front();
            TreeNode* p2 = q2.front();
            
            // 注意层序遍历的终止条件即可
            if (!p1 && !p2)
            {
                continue;
            }
            if (p1 || p2)
            {
                return false;
            }
            if (p1->val != p2->val)
            {
                return false;
            }
            
            q1.pop_front();
            q2.pop_front();
            
            q1.push_back(p1->left);
            q1.push_back(p1->right);
            q2.push_back(p2->right);
            q2.push_back(p2->left);         
        }
        
        return true;
    }
};
