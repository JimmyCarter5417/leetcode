// Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

// Example 1:

// Input: "ab-cd"
// Output: "dc-ba"
// Example 2:

// Input: "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:

// Input: "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
 

// Note:

// S.length <= 100
// 33 <= S[i].ASCIIcode <= 122 
// S doesn't contain \ or "

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0;
        int right = S.size() - 1;
        
        while (left < right)
        {
            while (!isalpha(S[left]))
            {
                left++;
            }
            
            while (!isalpha(S[right]))
            {
                right--;
            }
            
            if (left < right)
            {
                swap(S[left], S[right]);
            
                left++;
                right--;
            }
        }
        
        return S;
    }
};