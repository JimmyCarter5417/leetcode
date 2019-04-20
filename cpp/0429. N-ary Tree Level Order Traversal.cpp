// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example, given a 3-ary tree:

// We should return its level order traversal:
// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
 

// Note:
// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
        {
            return {};
        }
        
        vector<vector<int>> res;
        queue<Node*> q; // 与二叉树层序遍历相同
        
        q.push(root);
        
        while (!q.empty())
        {
            int len = q.size();
            res.push_back({});
            
            for (int i = 0; i < len; i++)
            {
                Node* p = q.front();
                q.pop();
                
                res.back().push_back(p->val);
                
                for (Node* child: p->children)
                {
                    q.push(child);
                }
            }
        }
        
        return res;
    }
};