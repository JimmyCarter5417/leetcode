// Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

// Example 1:
// Input: 12
// Output: 21 

// Example 2:
// Input: 21
// Output: -1


class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long long res = stoll(str);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};