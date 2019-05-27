// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

// Note:

// If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// All airports are represented by three capital letters (IATA code).
// You may assume all tickets form at least one valid itinerary.
// Example 1:

// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
// Example 2:

// Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
//              But it is larger in lexical order.


class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto p: tickets)
            m[p.first].insert(p.second);
        
        dfs(m, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(unordered_map<string, multiset<string>>& m, string str, vector<string>& res)
    {
        while (!m[str].empty())
        {
            string t = *m[str].begin();
            m[str].erase(m[str].begin());
            // 每次提取最小值，直至提取完
            dfs(m, t, res);
        }
        
        res.push_back(str);
    }
};