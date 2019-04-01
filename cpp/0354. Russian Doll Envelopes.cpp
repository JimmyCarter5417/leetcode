// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

// What is the maximum number of envelopes can you Russian doll? (put one inside other)

// Note:
// Rotation is not allowed.

// Example:

// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3 
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).


// LIS，与0300. Longest Increasing Subsequence.cpp类似
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> dp; 
        sort(envelopes.begin(), envelopes.end(), // 排序是关键
            [](const pair<int, int>& a, const pair<int, int>& b)
             {
                 if (a.first == b.first)
                 {
                     return a.second > b.second; // 这里很关键！！一定要把高度大的放前面，因为相同宽度不能嵌套，放后面的话就变成合法的LIS序列了
                 }
                 
                 return a.first < b.first;
             });
        
        for (auto a: envelopes)
        {
            auto itr = lower_bound(dp.begin(), dp.end(), a.second);
            if (itr == dp.end())
            {
                dp.push_back(a.second);
            }
            else
            {
                *itr = a.second;
            }
        }
        
        return dp.size();
    }
};