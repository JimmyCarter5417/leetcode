// Given a nested list of integers represented as a string, implement a parser to deserialize it.

// Each element is either an integer, or a list -- whose elements may also be integers or other lists.

// Note: You may assume that the string is well-formed:

// String is non-empty.
// String does not contain white spaces.
// String contains only digits 0-9, [, - ,, ].
// Example 1:

// Given s = "324",

// You should return a NestedInteger object which contains a single integer 324.
// Example 2:

// Given s = "[123,[456,[789]]]",

// Return a NestedInteger object containing a nested list with 2 elements:

// 1. An integer containing value 123.
// 2. A nested list containing two elements:
//     i.  An integer containing value 456.
//     ii. A nested list with one element:
//          a. An integer containing value 789.


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        function<bool(char)> isnumber = [](char ch)
        {
            return (ch >= '0' && ch <= '9') || (ch == '-');
        };
        
        stack<NestedInteger> stk;
        // 要先push一个空的NestedInteger，保证最终的结果总是NestedInteger，如123、[123]都可以得到NestedInteger
        stk.push(NestedInteger()); 
        
        for (auto itr = s.begin(); itr != s.end(); )
        {
            if (isnumber(*itr))
            {
                auto end = find_if_not(itr, s.end(), isnumber);
                stk.top().add(NestedInteger(stoi(string(itr, end)))); // 注意：是在top里add
                
                itr = end;
            }
            else if (*itr == '[')
            {
                stk.push(NestedInteger()); // 新建NestedInteger
                
                ++itr;
            }
            else if (*itr == ']')
            {
                NestedInteger ni = stk.top();
                stk.pop();
                stk.top().add(ni); // 注意：是将top取出，再add到新的top
                
                ++itr;
            }
            else //,
            {
                ++itr;
            }
        }

        // 最终，栈里应该只有一个NestedInteger，但嵌套在最开始创建的NestedInteger里面
        // 如：  123  -> [123]
        //     [123] -> [[123]]
        //     [123,[456]] -> [[123,[456]]]
        return stk.top().getList().front(); 
    }
};