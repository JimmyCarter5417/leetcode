// Given a positive integer K, you need find the smallest positive integer N such that N is divisible by K, and N only contains the digit 1.

// Return the length of N.  If there is no such N, return -1.

// Example 1:

// Input: 1
// Output: 1
// Explanation: The smallest answer is N = 1, which has length 1.
// Example 2:

// Input: 2
// Output: -1
// Explanation: There is no such positive integer N divisible by 2.
// Example 3:

// Input: 3
// Output: 3
// Explanation: The smallest answer is N = 111, which has length 3.

// Note:

// 1 <= K <= 10^5


class Solution {
	    public int smallestRepunitDivByK(int K) {
	    	  long x = 0;
          
	        for(int len = 1; len <= 1e6; len++) // 最大10^6？
          {
	        	  x = (x * 10 + 1) % K;
	        	  if(x == 0)
              {
	        		    return len;
	        	  }
	        }
          
	        return -1;
	    }
	}
