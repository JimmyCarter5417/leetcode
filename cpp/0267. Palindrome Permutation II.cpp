// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

// For example:

// Given s = "aabb", return ["abba", "baab"].

// Given s = "abc", return [].

// Hint:

// If a palindromic permutation exists, we just need to generate the first half of the string.
// To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.


// solution I: DFS
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string t; // 待遍历的集合
        string mid; // 中间的一个或0个字符

        for (auto a : s) 
            ++m[a];

        for (auto &it : m) 
        {
            if (it.second % 2 == 1) 
                mid += it.first;

            it.second /= 2; // 注意：需要减半
            t += string(it.second, it.first);

            if (mid.size() > 1) 
                return {};
        }

        permute(t, m, mid, "", res);

        return res;
    }

    void permute(string &t, unordered_map<char, int> &m, string mid, string out, vector<string> &res) 
    {
        if (out.size() >= t.size()) 
        {
            res.push_back(out + mid + string(out.rbegin(), out.rend()));
            return;
        } 

        for (auto &it : m) 
        {
            if (it.second > 0) // 还有可用的字符
            {
                --it.second;
                permute(t, m, mid, out + it.first, res);
                ++it.second;
            }
        }
    }
};

// solution II: next_permutation
class Solution {
public:
    vector<string> generatePalindromes(string s) 
    {
        vector<string> res;
        unordered_map<char, int> m;
        string t;
        string mid;
        for (auto a : s) 
            ++m[a];

        for (auto it : m) 
        {
            if (it.second % 2 == 1) 
                mid += it.first;

            t += string(it.second / 2, it.first);
            if (mid.size() > 1) 
                return {};
        }

        sort(t.begin(), t.end());

        do 
        {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        } while (next_permutation(t.begin(), t.end())); // next_permutation简化处理
        
        return res;
    }
};