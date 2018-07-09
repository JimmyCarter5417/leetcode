// Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

// Example 1:

// Input: A = "ab", B = "ba"
// Output: true
// Example 2:

// Input: A = "ab", B = "ab"
// Output: false
// Example 3:

// Input: A = "aa", B = "aa"
// Output: true
// Example 4:

// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
// Example 5:

// Input: A = "", B = "aa"
// Output: false
 

// Note:

// 0 <= A.length <= 20000
// 0 <= B.length <= 20000
// A and B consist only of lowercase letters.

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
        {
            return false;
        }
        
        int sameCharCntArray[26] = {0};// 记录所有相同字符出现的次数   
        int maxSameCharCnt = 0;// 记录所有相同字符出现的最大次数   
        int diffCharCnt = 0;// 记录不同字符出现的次数
        char diffCharA1, diffCharA2, diffCharB1, diffCharB2;// 记录前两组不同字符
        
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == B[i])
            {             
                maxSameCharCnt = max(maxSameCharCnt, ++sameCharCntArray[A[i] - 'a']);
            }
            else
            {
                ++diffCharCnt;
                
                if (diffCharCnt == 1)
                {
                    diffCharA1 = A[i];
                    diffCharB1 = B[i];
                }
                else if (diffCharCnt == 2)
                {
                    diffCharA2 = A[i];
                    diffCharB2 = B[i];
                }
                if (diffCharCnt >= 3)
                {
                    break;
                }
            }
        }
        
        if (diffCharCnt == 0)
        {
            if (maxSameCharCnt >= 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (diffCharCnt == 1)
        {
            return false;
        }
        else if (diffCharCnt == 2)
        {
            if (diffCharA1 == diffCharB2 && diffCharA2 == diffCharB1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else// 不可能出现
        {
            return false;
        }
    }
};