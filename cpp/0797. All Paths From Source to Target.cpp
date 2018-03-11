// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

// Example:
// Input: [[1,2], [3], [3], []] 
// Output: [[0,1,3],[0,2,3]] 
// Explanation: The graph looks like this:
// 0--->1
// |    |
// v    v
// 2--->3
// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Note:

// The number of nodes in the graph will be in the range [2, 15].
// You can print different paths in any order, but you should keep the order of nodes inside one path.

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, path, 0, graph.size() - 1);
        return paths;
    }
    
    void dfs(const vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int src, int dst)
    { 
        // 因为path传递的是引用，所以需要push/pop，直接传值的话就不需要了，开始位置一个push即可
        // path.push_back(src);
        
        if (src == dst)
        {
            path.push_back(src);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        
        for (int node: graph[src])
        {
            path.push_back(src);
            dfs(graph, paths, path, node, dst);
            path.pop_back();
        }
        
        return;
    }
};
