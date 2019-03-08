//Count the number of prime numbers less than a non-negative number, n.
//
//Example:
//
//Input: 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//


class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
        {
            return 0;
        }

        // 筛素数法
        vector<bool> flag(n - 1, true);
        int end = sqrt(n); // 最大取到n的平方根
        flag[0] = false;
        
        for (int i = 2; i <= end; ++i)
        {
            if (flag[i - 1])
            {
                for (int j = 2 * i; j < n; j += i)
                {
                    flag[j - 1] = false;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < flag.size(); ++i)
        {
            if (flag[i])
            {
                res++;
            }
        }
        
        return res;
    }
};

