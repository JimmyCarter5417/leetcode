// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

// Example 1:

// Input: "2-1-1"
// Output: [0, 2]
// Explanation: 
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
// Explanation: 
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10


// a classical solution!
// 与Unique Binary Search Trees II类似的解法
// calculator类型的题目
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        
        for (int i = 1; i < input.size(); i++)
        {
            if (isdigit(input[i]))
            {
                continue;
            }
            
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            
            for (int m: left)
            {
                for (int n: right)
                {
                    if (input[i] == '+')
                    {
                        res.push_back(m + n);
                    }
                    else if(input[i] == '-')
                    {
                        res.push_back(m - n);
                    }
                    else if (input[i] == '*')
                    {
                        res.push_back(m * n);
                    }
                }
            }
        }        
        
        if (res.empty())
        {
            res.push_back(stoi(input));
        }
        
        return res;
    }
};
