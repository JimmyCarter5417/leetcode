// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
// Could you do this in O(n) runtime?

// Example:
// Input: [3, 10, 5, 25, 2, 8]
// Output: 28
// Explanation: The maximum result is 5 ^ 25 = 28.


// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/130427/()-92
class Solution {
    struct TrieNode
    {
        TrieNode* left;
        TrieNode* right;
        int val;
        
        TrieNode(int v) : left(NULL), right(NULL), val(v)
        {
            
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = 0;
        TrieNode* root = new TrieNode(-1); // 字典树根节点
        TrieNode* cur = root;
        
        for (int n: nums)
        {
            cur = root;
            
            for (int i = 31; i >= 0; i--)
            {
                int tmp = n & (1 << i);
                
                if (tmp) // 1放到左子节点
                {
                    if (!cur->left)
                    {
                        cur->left = new TrieNode(1);
                    }
                    
                    cur = cur->left;
                }
                else // 0放到右子节点
                {
                    if (!cur->right)
                    {
                        cur->right = new TrieNode(0);
                    }
                    
                    cur = cur->right;
                }
            }                
        }
        
        for (int n: nums)
        {
            cur = root;
            int res = 0;
            
            for (int i = 31; i >= 0; i--)
            {
                int tmp = n & (1 << i);
                
                if (cur->left && cur->right) // 左右都有数字
                {
                    if (tmp) // 异或运算，取与tmp相反的节点
                    {
                        cur = cur->right; // right为0
                    }
                    else
                    {
                        cur = cur->left; // left为1
                    }
                }
                else // 左右子节点只有一个有数字，注意，不可能出现左右都没有数字的情况
                {
                    if (cur->left)
                    {
                        cur = cur->left;
                    }
                    else
                    {
                        cur = cur->right;
                    }
                }
                
                res += tmp ^ (cur->val << i);
            }
                        
            mx = max(mx, res);
        }
        
        return mx;
    }
};
