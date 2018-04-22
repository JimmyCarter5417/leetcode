// On a table are N cards, with a positive integer printed on the front and back of each card (possibly different).

// We flip any number of cards, and after we choose one card. 

// If the number X on the back of the chosen card is not on the front of any card, then this number X is good.

// What is the smallest number that is good?  If no number is good, output 0.

// Here, fronts[i] and backs[i] represent the number on the front and back of card i. 

// A flip swaps the front and back numbers, so the value on the front is now on the back and vice versa.

// Example:

// Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
// Output: 2
// Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
// We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so 2 is good.
 

// Note:

// 1 <= fronts.length == backs.length <= 1000.
// 1 <= fronts[i] <= 2000.
// 1 <= backs[i] <= 2000.

/*
 前后数字相同肯定排除，剩余数字里查找最小即可
*/
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int res = INT_MAX;
        unordered_set<int> s;
        
        for (int i = 0; i < fronts.size(); i++)
        {
            if (fronts[i] == backs[i])
                s.insert(fronts[i]);
        }
        
        for (int i = 0; i < fronts.size(); i++)
        {
            int t1 = INT_MAX;
            int t2 = INT_MAX;
            
            if (0 == s.count(fronts[i]))
                t1 = fronts[i];
            if (0 == s.count(backs[i]))
                t2 = backs[i];
            res = min(res, min(t1, t2));
        }
        
        return res == INT_MAX ? 0 :res;
    }
};
