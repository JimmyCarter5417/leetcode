// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5


//https://discuss.leetcode.com/topic/16797/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if (n1 < n2)
            return findMedianSortedArrays(nums2, nums1);
            
        if (n2 == 0)
            return (nums1[(n1-1)/2] + nums1[n1/2]) / 2.0;
            
        int left = 0;
        int right = 2 * n2 + 1;
        while (left <= right)
        {
            int mid2 = (left + right) / 2;
            int mid1 = n1 + n2 - mid2;
            
            int L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            int L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            int R1 = (mid1 == 2 * n1) ? INT_MAX : nums1[mid1/2];
            int R2 = (mid2 == 2 * n2) ? INT_MAX : nums2[mid2/2];
            
            if (L1 > R2)
                left = mid2 + 1;
            else if (L2 > R1)
                right = mid2 - 1;
            else 
                return (max(L1, L2) + min(R1, R2)) / 2.0;
        }
        
        return -1;
    }
};
