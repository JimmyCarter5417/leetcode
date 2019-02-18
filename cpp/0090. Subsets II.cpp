// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
  // [2],
  // [1],
  // [1,2,2],
  // [2,2],
  // [1,2],
  // []
// ]


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }
        
        vector<vector<int>> res;
        vector<int> out;
        
        sort(nums.begin(), nums.end());
        dfs(nums, 0, out, res);
        
        return res;
    }
    
    void dfs(const vector<int>& nums, int level, vector<int>& out, vector<vector<int>>& res)
    {
        res.push_back(out);
        
        for (int i = level; i < nums.size(); i++)
        {
            // if (i == nums.size() - 1 || nums[i] != nums[i + 1]) // 不能在这里过滤！！！
            {                
                out.push_back(nums[i]);
                dfs(nums, i + 1, out, res);
                out.pop_back();
            }
            
            // 一定要注意：过滤条件不能在上面做，必须在上面处理完后再做
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
    }
};