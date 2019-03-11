// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:

// Input: 2, [[1,0]] 
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
// Note:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visit(numCourses, 0);
        
        for (const pair<int, int>& p: prerequisites)
        {
            graph[p.first].push_back(p.second);
        }
        
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(graph, i, visit)) // 一旦有一个课程不符合，即返回
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs(const vector<vector<int>>& graph, int next, vector<int>& visit)
    {
        if (next == graph.size())
        {
            return true;
        }
        if (visit[next] == -1) // 已经用过了
        {
            return false;
        }
        if (visit[next] == 1) // 尚未用过
        {
            return true;
        }
        
        visit[next] = -1; // -1 0 1三种状态
        
        for (int i = 0; i < graph[next].size(); i++)
        {
            if (!dfs(graph, graph[next][i], visit)) // 一旦有一个课程不符合，即返回
            {
                return false;
            }
        }
        
        visit[next] = 1;
        
        return true;
    }
};
