// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:

// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:

// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


// solution I: 哈希
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mm;
        
        for (auto n: nums1)
        {
            if (mm.end() == mm.find(n))
                mm[n] = 1;
            else
                ++mm[n];
        }
        
        for (auto n: nums2)
        {
            if (mm.end() != mm.find(n) && mm[n] > 0)
            {
                res.push_back(n);
                --mm[n];
            }
        }
        
        return res;
    }
};

// solution II: 双指针
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {        
        vector<int> res;
        int n1 = 0;
        int n2 = 0;
        
        // 先排序
        // 如果nums2在磁盘上，可以将nums1排序，逐个在nums1中二分查找，并删除已取出的数字
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while (n1 < nums1.size() && n2 < nums2.size())
        {
            if (nums1[n1] < nums2[n2])
            {
                n1++;
            }
            else if (nums1[n1] > nums2[n2])
            {
                n2++;
            }
            else
            {
                res.push_back(nums1[n1]);
                n1++;
                n2++;
            }
        }
        
        return res;
    }
};