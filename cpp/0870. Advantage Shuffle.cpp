// Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

// Return any permutation of A that maximizes its advantage with respect to B.

 

// Example 1:

// Input: A = [2,7,11,15], B = [1,10,4,11]
// Output: [2,11,7,15]
// Example 2:

// Input: A = [12,24,8,32], B = [13,25,32,11]
// Output: [24,32,8,12]
 

// Note:

// 1 <= A.length = B.length <= 10000
// 0 <= A[i] <= 10^9
// 0 <= B[i] <= 10^9

// 贪心算法，每次从A中选择可选的最小值，不存在则选择自己的最小值
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> res;
        map<int, int> m;
        
        for (int val: A)
        {
            m[val]++;
        }
        
        for (int val: B)
        {
            int tmp;
            auto it = m.upper_bound(val);
            
            if (m.end() == it)
            {
                tmp = m.begin()->first;
            }
            else
            {
                tmp = it->first;
            }
            res.push_back(tmp);
            
            if (--m[tmp]== 0)
            {
                m.erase(tmp); // 记得删除已使用的数字
            }
        }
        
        return res;
    }
};