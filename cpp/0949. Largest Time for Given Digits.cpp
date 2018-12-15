// Given an array of 4 digits, return the largest 24 hour time that can be made.

// The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

// Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

// Example 1:

// Input: [1,2,3,4]
// Output: "23:41"
// Example 2:

// Input: [5,5,5,5]
// Output: ""
 

// Note:

// A.length == 4
// 0 <= A[i] <= 9


class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        char res[6] = {0};
        int time = INT_MIN;
        
        // 简单遍历全排列即可
        for (int i = 0; i < 24; i++)
        {
            if (isTimeValid(A))
            {
                int tmp = (10 * A[0] + A[1]) * 60 + (10 * A[2] + A[3]);
                if (time < tmp)
                {
                    time = tmp;
                    snprintf(res, 6, "%d%d:%d%d", A[0], A[1], A[2], A[3]);
                }
            }
            
            next_permutation(A.begin(), A.end());
        }
        
        return res;
    }
    
    bool isTimeValid(const vector<int>& A)
    {
        if ((10 * A[0] + A[1]) > 23)
            return false;
        if ((10 * A[2] + A[3]) > 59)
            return false;
        return true;
    }
};