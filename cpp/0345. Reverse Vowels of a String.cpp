// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:

// Input: "hello"
// Output: "holle"
// Example 2:

// Input: "leetcode"
// Output: "leotcede"
// Note:
// The vowels does not include the letter "y".


class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right)
        {
            // 注意不要越界即可
            while (left >= 0 && left < s.size() && !isVowels(s[left]))
            {
                left++;
            }
            
            while (right >= 0 && right < s.size() && !isVowels(s[right]))
            {
                right--;
            }
            
            if (left < right)
            {
                swap(s[left++], s[right--]);
            }            
            
        }
        
        return s;
    }
    
    bool isVowels(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
};