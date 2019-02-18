// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string. 

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"


class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        while (--n > 0)
        {
            // 注意记录重复元素及其个数即可
            int start = 0;
            int cnt = 0;
            string tmp;
            
            for (int i = 0; i < res.size(); i++)
            {
                if (res[i] == res[start])
                {
                    cnt++;
                }
                else
                {
                    tmp.push_back('0' + cnt);
                    tmp.push_back(res[start]);
                    
                    start = i;
                    cnt = 1;
                }                
            }
            
            tmp.push_back('0' + cnt);
            tmp.push_back(res[start]);
            
            res = tmp;
        }
        
        return res;
    }
};