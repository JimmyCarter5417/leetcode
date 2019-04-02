// For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Example 1 :

// Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

//         0
//         |
//         1
//        / \
//       2   3 

// Output: [1]
// Example 2 :

// Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5 

// Output: [3, 4]
// Note:

// According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


// 剥洋葱，与0366. Find Leaves of Binary Tree类似
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1)
            return {0};
            
        vector<int> res;
        vector<unordered_set<int>> graph(n);
        queue<int> q;
        
        for (auto e: edges)
        {
            graph[e.first].insert(e.second); // 无向图，要将双向边都加入graph
            graph[e.second].insert(e.first);
        }
        
        for (int i = 0; i < graph.size(); ++i)
        {
            if (graph[i].size() == 1) // 将叶子节点入队列
                q.push(i);
        }
        
        // example: 
        // 1 -- 2 -- 3
        // 1/3入队列
        // 1弹出，从2的相邻节点中删除1，2入队列
        // 3弹出，从2的相邻节点中删除3，此时2相邻节点为空，且已经在队列中
        
        while (n > 2) // 最终结果必定是一个或两个节点，除非有环？
        {
            int size = q.size();
            n -= size;
            
            for (int i = 0; i < size; ++i)
            {
                int m = q.front(); // 删除m节点
                q.pop();
                
                for (auto a: graph[m]) // 遍历与m相邻的所有节点
                {
                    graph[a].erase(m); // 从a中删除相邻的m节点
                    
                    if (graph[a].size() == 1) // a节点的度变为0，即成为了类似于“叶子结点”，可入队列
                        q.push(a);
                }
            }
        }
        
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
