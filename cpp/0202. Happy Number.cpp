//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example: 
//
//Input: 19
//Output: true
//Explanation: 
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1
//


class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        // 利用set记录所有循环数字
        while (n >= 1) // 循环节必定包含4？？？
        {
            int sum = 0;
            while (n >= 1)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            
            if (s.end() != s.find(sum)) // 找到循环
            {
                return sum == 1;
            }
            else
            {
                s.insert(sum);
                n = sum;
            }
        }
        
        return false;
    }
};

