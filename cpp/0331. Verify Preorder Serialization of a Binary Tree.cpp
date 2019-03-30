// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

// Example 1:

// Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true
// Example 2:

// Input: "1,#"
// Output: false
// Example 3:

// Input: "9,#,#,1"
// Output: false


class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = 0;
        vector<string> v;
        
        stringstream ss(preorder);
        string tmp;
        while (getline(ss, tmp, ','))
            v.push_back(tmp);
            
        // 数字的个数总是比#号少一个
        // 最后一个一定是#号
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] == "#")
                --n;
            else
                ++n;
                
            if (n < 0 && i != v.size() - 1)
                return false;
        }
        
        return n == -1;
    }
};