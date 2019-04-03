// Assume you have an array of length n initialized with all 0's and are given k update operations.

// Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

// Return the modified array after all k operations were executed.

// Example:

// Given:

//     length = 5,
//     updates = [
//         [1,  3,  2],
//         [2,  4,  3],
//         [0,  2, -2]
//     ]

// Output:

//     [-2, 0, 3, 5, 3]
// Explanation:

// Initial state:
// [ 0, 0, 0, 0, 0 ]

// After applying operation [1, 3, 2]:
// [ 0, 2, 2, 2, 0 ]

// After applying operation [2, 4, 3]:
// [ 0, 2, 5, 5, 3 ]

// After applying operation [0, 2, -2]:
// [-2, 0, 3, 5, 3 ]
// Hint:

// Thinking of using advanced data structures? You are thinking it too complicated.
// For each update operation, do you really need to update all elements between i and j?
// Update only the first and end element is sufficient.
// The optimal time complexity is O(k + n) and uses O(1) extra space.
// Credits:
// Special thanks to @vinod23 for adding this problem and creating all test cases.


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1, 0); 
        for (auto a : updates) 
        {
            res[a[0]] += a[2];
            res[a[1] + 1] -= a[2]; // 多出的一个是为末尾的下一个位置准备的，实际上用不到的

        }

        for (int i = 1; i < res.size(); ++i) 
        {
            res[i] += res[i - 1]; // 加上上一位置，正正相加，或正负抵消
        }

        res.pop_back(); // 弹出没用的末尾元素
        
        return res;
    }
}