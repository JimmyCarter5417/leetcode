// In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

// Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

// Which nodes are eventually safe?  Return them as an array in sorted order.

// The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

// Example:
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Here is a diagram of the above graph.

// Illustration of graph

// Note:

// graph will have length at most 10000.
// The number of edges in the graph will not exceed 32000.
// Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        vector<int> visit(graph.size(), 0);
        
        for (int i = 0; i < graph.size(); i++)
        {
            // if (!dfs(graph, i, visit))
            if (dfs(graph, i, visit))
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
    
    // 节点着色，进行剪枝处理
    // 0：未访问
    // 1：初次访问
    // 2：叶子节点、或者有叶子节点的安全节点
    bool dfs(const vector<vector<int>>& graph, int n, vector<int>& visit)
    {
        if (visit[n] > 0)
        {
            return visit[n] == 2;
        }
        
        visit[n] = 1;
        
        for (int i: graph[n])
        {
            if (visit[i] == 2)
                continue;
            
            if (visit[i] == 1 || !dfs(graph, i, visit))
            {   
                return false;
            }
        }

        visit[n] = 2;  
        return true;
    }
    
    // TLE solution
    // 判断是否存在环
    /*bool dfs(const vector<vector<int>>& graph, int n, vector<bool>& visit)
    {
        if (visit[n])
        {
            return true;
        }
        // 标志位置位        
        visit[n] = 1;        
        
        for (int i = 0; i < graph[n].size(); i++)
        {
            // 存在任意一个环，则为true
            if (dfs(graph, graph[n][i], visit))
            {   
                // 标志位置位        
                visit[n] = 0;    
                return true;
            }
        }
        // 标志位复位
        visit[n] = 0;  
        // 没有任何环，则为false
        return false;
    }*/
};