// A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

// Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

// If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

// Note:

// The number of stones is ≥ 2 and is < 1,100.
// Each stone's position will be a non-negative integer < 231.
// The first stone's position is always 0.

// Example 1:

// [0,1,3,5,6,8,12,17]

// There are a total of 8 stones.
// The first stone at the 0th unit, second stone at the 1st unit,
// third stone at the 3rd unit, and so on...
// The last stone at the 17th unit.

// Return true. The frog can jump to the last stone by jumping 
// 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
// 2 units to the 4th stone, then 3 units to the 6th stone, 
// 4 units to the 7th stone, and 5 units to the 8th stone.

// Example 2:

// [0,1,2,3,4,8,9,11]

// Return false. There is no way to jump to the last stone as 
// the gap between the 5th and 6th stone is too large.


class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> s; // 记录所有false的走法，用于加速
        return dfs(stones, 0, 0, s);
    }
    
    bool dfs(const vector<int>& stones, int idx, int jump, unordered_set<int>& s)
    {
        if (idx == stones.size() - 1)
        {
            return true;
        }            
        
        int key = idx | (jump<<11); // 以位置和步数为索引
        auto itr = s.find(key); // 这里要先查找，因为前面的递归有可能已经得到了该位置是否能成功的结果，避免重复递归
        if (itr != s.end())
        {
            return false;
        }    
            
        for (int i = idx + 1; i < stones.size(); ++i)
        {
            int diff = stones[i] - stones[idx];
            
            // 三种情况
            if (diff < jump - 1) // 肯定可以跳过去
            {
                continue;
            }  
            else if (diff > jump + 1) // 跳不过去，记录下来并返回，因为后面的位置更不可能跳过去了
            {
                break;
            }
            else // diff == jump or jump + 1 or jump - 1
            {
                if (dfs(stones, i, diff, s)) // 递归判断后面的位置，一旦发现一个合法的走法，即可返回true
                {
                    return true;
                }
            }
            
        }
        
        s.insert(key);
        return false;
    }
};
