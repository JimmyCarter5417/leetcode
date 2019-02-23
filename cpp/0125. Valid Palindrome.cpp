//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//Note: For the purpose of this problem, we define empty string as valid palindrome.
//
//Example 1:
//
//Input: "A man, a plan, a canal: Panama"
//Output: true
//Example 2:
//
//Input: "race a car"
//Output: false
//


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; 
        int right = s.size() - 1;
        
        while (left < right)
        {
            // 忽略空白字符
            while (!isalnum(s[left]))
            {
                ++left;
            }
            
            while (left < right && !isalnum(s[right]))
            {
                --right;
            }
                
            if (left < right)
            {
                // 注意忽略大小写
                if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)
                {
                    return false;
                }
                else
                {
                    ++left;
                    --right;
                }
            }           
        }
        
        return true;
    }
};

