// Implement pow(x, n).
//
//
// Example 1:
//
// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:
//
// Input: 2.10000, 3
// Output: 9.26100


class Solution {
public:
    double myPow(double x, int n) {        
        if (n < 0)
        {
            if (n == INT_MIN)
                return 1 / (myPow(x, INT_MAX) * x);
            else
                return 1 / myPow(x, -n);
        }
        else
        {
            double res = 1;
            
            for (int i = n; i >= 1; i /= 2)
            {
                if (i&1)
                {
                    res *= x;
                    if (res > INT_MAX)
                        return INT_MAX;
                }    

                x *= x;
            }
            
            return res;
        }        
    }
};
