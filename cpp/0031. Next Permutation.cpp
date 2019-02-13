// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place and use only constant extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1


class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, j, n = num.size();
        
        // 1　　2　　7　　4　　3　　1
        // 下一个排列为：
        // 1　　3　　1　　2　　4　　7
        // 从后往前找第一个比2大的数字，是3
        // 交换2和3，再把此时3后面的所有数字转置一下即可
        for (i = n - 2; i >= 0; --i) 
        {
            if (num[i + 1] > num[i]) 
            {
                for (j = n - 1; j >= i; --j) 
                {
                    if (num[j] > num[i]) 
                    {
                        break;
                    }    
                }
                
                swap(num[i], num[j]);
                reverse(num.begin() + i + 1, num.end());
                
                return;
            }
        }
        
        reverse(num.begin(), num.end());
    }
};
