# sorting problems  
a common solution for sorting problems, just like this [Sort Colors](https://leetcode.com/problems/sort-colors/)

```
void partition(vector<int> & nums, vector<int> const & pivots)
{
    vector<int> boundaries(pivots.size());
    for (auto &n : nums)
    {
        for (int i = 0; i < pivots.size(); ++ i)
            if (n < pivots[i])
                swap(n, nums[boundaries[i] ++]);
        for (int i = 1; i < pivots.size(); ++ i)
            boundaries[i] = max(boundaries[i], boundaries[i - 1]);
    }
}
```
