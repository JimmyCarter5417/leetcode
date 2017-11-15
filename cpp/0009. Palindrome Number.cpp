// Determine whether an integer is a palindrome. Do this without extra space.
//
// click to show spoilers.
//
// Some hints:
// Could negative integers be palindromes? (ie, -1)
//
// If you are thinking of converting the integer to string, note the restriction of using extra space.
//
// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
//
// There is a more generic way of solving this problem.


// naive solution
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         /*return x == Reverse(x);*/
//        
//         int old_num = x;
//         int rev_num = 0;
//         while (x)
//         {
//             rev_num = 10 * rev_num + x % 10;
//             x /= 10;
//         }
//        
//         return old_num == rev_num;
//     }
//    
//     int Reverse(int x)
//     {
//         int num;
//         while (x)
//         {
//             num = 10 * num + x % 10;
//             x /= 10;
//         }
//         return num;
//     }
// };


class Solution {
public:
    bool isPalindrome(int x){
        if (x < 0 || (x % 10 == 0 && x != 0))// 1220
            return false;
        
        int reverseNum = 0;
        while (x > reverseNum)
        {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }
        
        return x == reverseNum || x == reverseNum / 10;// 121
    }
};
