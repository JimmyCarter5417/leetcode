// Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

// Example:

// Input: citations = [0,1,3,5,6]
// Output: 3 
// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
//              received 0, 1, 3, 5, 6 citations respectively. 
//              Since the researcher has 3 papers with at least 3 citations each and the remaining 
//              two with no more than 3 citations each, her h-index is 3.
// Note:

// If there are several possible values for h, the maximum one is taken as the h-index.

// Follow up:

// This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
// Could you solve it in logarithmic time complexity?


// 本质上属于二分查找第一个出现的位置
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = -1;
        int left = 0;
        int right = citations.size() - 1;
        
        while (left <= right) // 注意二分法各种边界条件
        {
            int mid = left + (right - left) / 2;
            int t = citations.size() - mid;
            
            if (citations[mid] == t)
            {
                return t;
            }
            else if (citations[mid] < t)
            {
                left = mid + 1;                
            }
            else
            {
                right = mid - 1;                
            }
        }
        
        return citations.size() - left;
    }
};
