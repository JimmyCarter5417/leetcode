//Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
//
//Example:
//
//Input:
//{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}
//
//Explanation:
//Node 1's value is 1, and it has two neighbors: Node 2 and 4.
//Node 2's value is 2, and it has two neighbors: Node 1 and 3.
//Node 3's value is 3, and it has two neighbors: Node 2 and 4.
//Node 4's value is 4, and it has two neighbors: Node 1 and 3.
// 
//
//Note:
//
//The number of nodes will be between 1 and 100.
//The undirected graph is a simple graph, which means no repeated edges and no self-loops in the graph.
//Since the graph is undirected, if node p has node q as neighbor, then node q must have node p as neighbor too.
//You must return the copy of the given node as a reference to the cloned graph.
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m; // 用来记录所有的新旧图节点的映射关系，方便查找
        return dfs(node, m);
    }
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& m)
    {
        if (!node)
        {
            return NULL;
        }
        
        auto itr = m.find(node);
        if (itr != m.end())
        {
            return itr->second;
        }
        
        Node* res = new Node(node->val);
        m[node] = res;
        for (Node* p: node->neighbors)
        {
            res->neighbors.push_back(dfs(p, m)); // 递归设置新节点的邻居节点
        }
        
        return res;
    }
};

