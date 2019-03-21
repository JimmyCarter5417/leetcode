// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
// Note: If the given node has no in-order successor in the tree, return null.


// solution I: 通用方法
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        bool b = false;
        TreeNode *t = root;
        while (t || !s.empty()) 
        {
            while (t) 
            {
                s.push(t);
                t = t->left;
            }
            
            t = s.top(); 
            s.pop();
            
            // 与普通的中序遍历相比，多了下面两个判断，可以作为通用的前驱后驱节点的处理方法
            if (b) 
                return t;
            if (t == p) 
                b = true;
                
            t = t->right;
        }
        return NULL;
    }
};

// solution II: 利用BST性质
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode *res = NULL;
        
        while (root) 
        {
            if (root->val > p->val) // BST中的后驱节点必定大于当前节点
            {
                res = root;
                root = root->left;
            } 
            else 
            {
                root = root->right;
            }
        }
        
        return res;
    }
};
