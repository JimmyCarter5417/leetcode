// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: 2, [[1,0]] 
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
//              course 0. So the correct course order is [0,1] .
// Example 2:

// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
// Note:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<int> in(numCourses, 0); // 记录每个节点的入度
        vector<vector<int>> graph(numCourses);
        queue<int> q;
        
        for (pair<int, int> p: prerequisites)
        {
            graph[p.second].push_back(p.first); // second->first
            in[p.first]++;
        }
        
        for (int i = 0; i < in.size(); i++)
        {
            if (in[i] == 0)
            {
                q.push(i); // 初始入度为0，才有可能作为起点
            }
        }
        
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            
            res.push_back(course);
            
            for (int next: graph[course])
            {
                if (--in[next] == 0) // 因为course已经拿出来了，所以next的入度要减一，为0即可拿出来
                {
                    q.push(next);
                }
            }
        }
        
        if (res.size() != numCourses) // 有可能有些课程的入度仍然大于零，导致没有加入res，如：0->1, 1->2, 2->1
        {
            res.clear();
        }
        
        return res;
    }
};
