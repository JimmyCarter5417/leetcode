//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Return 0 if the array contains less than 2 elements.
//
//Example 1:
//
//Input: [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either
//             (3,6) or (6,9) has the maximum difference 3.
//Example 2:
//
//Input: [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
//Note:
//
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
//Try to solve it in linear time/space.
//


// HARD!!!
// solution I：桶排序
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }

        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int n: nums)
        {
            mn = min(mn, n);
            mx = max(mx, n);
        }

        int bucket_size = (mx - mn) / nums.size() + 1;
        int bucket_num = (mx - mn) / bucket_size + 1;

        vector<int> vMin(bucket_num, INT_MAX);
        vector<int> vMax(bucket_num, INT_MIN);

        for (int n: nums)
        {
            int idx = (n - mn) / bucket_size;
            vMin[idx] = min(vMin[idx], n);
            vMax[idx] = max(vMax[idx], n);
        }

        int pre = 0;
        int res = 0;

        for (int i = 1; i < bucket_num; ++i)
        {
            if (vMax[pre] != INT_MIN && vMin[i] != INT_MAX)
            {
                res = max(res, vMin[i] - vMax[pre]);
                pre = i;
            }
        }

        return res;
    }
};


// solution II：基数排序
class Solution {
public:
    int maximumGap(vector<int>& nums){
      if (nums.empty() || nums.size() < 2)
      return 0;

      int maxVal = *max_element(nums.begin(), nums.end());

      int exp = 1; // 1, 10, 100, 1000 ...
      int radix = 10; // base 10 system

      vector<int> aux(nums.size());

      /* LSD Radix Sort */
      while (maxVal / exp > 0) { // Go through all digits from LSD to MSD
      vector<int> count(radix, 0);

      for (int i = 0; i < nums.size(); i++) // Counting sort
           count[(nums[i] / exp) % 10]++;

      for (int i = 1; i < count.size(); i++) // you could also use partial_sum()
           count[i] += count[i - 1];

      for (int i = nums.size() - 1; i >= 0; i--)
           aux[--count[(nums[i] / exp) % 10]] = nums[i];

      for (int i = 0; i < nums.size(); i++)
           nums[i] = aux[i];

      exp *= 10;
      }

      int maxGap = 0;

      for (int i = 0; i < nums.size() - 1; i++)
           maxGap = max(nums[i + 1] - nums[i], maxGap);

      return maxGap;
    }
}
