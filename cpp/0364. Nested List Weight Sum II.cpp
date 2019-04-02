// Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

// Each element is either an integer, or a list -- whose elements may also be integers or other lists.

// Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

// Example 1:
// Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

// Example 2:
// Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17) 


// solution I: dfs
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> result;
        for(auto ni : nestedList) 
        {
            dfs(ni, 0, result);
        }

        //post processing
        int sum = 0;
        for(int i = result.size()-1,level = 1; i >=0; i--, level++) 
        {
            sum += result[i]*level;
        }

        return sum;
    }

private:
    void dfs(NestedInteger &ni, int depth, vector<int> & result) 
    {
        if(result.size() < depth+1) 
            result.resize(depth+1);

        if(ni.isInteger()) 
        {
            result[depth] += ni.getInteger();
        } 
        else 
        {
            for(auto n_ni : ni.getList()) 
            {
                dfs(n_ni, depth+1, result);
            }
        }
    }
};

// solution II: bfs
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0;
        int weighted = 0;
        queue<vector<NestedInteger>> q; // 也可以用queue<NestedInteger>

        q.push(nestedList);

        while (!q.empty()) 
        {
            int size = q.size();
            for (int i = 0; i < size; ++i) 
            {
                vector<NestedInteger> t = q.front(); 
                q.pop();

                for (auto a : t) 
                {
                    if (a.isInteger()) 
                        unweighted += a.getInteger();
                    else 
                        q.push(a.getList());
                }
            }

            weighted += unweighted; // 每一次都要加unweighted，相当于root最深
        }

        return weighted;
    }
};