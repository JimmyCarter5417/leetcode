// Write a program that outputs the string representation of numbers from 1 to n.

// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

// Example:

// n = 15,

// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        map<int, string> m; // 用map可以在需要额外处理很多的情况下，简化处理
        
        m[3] = "Fizz";
        m[5] = "Buzz";
        
        for (int i = 1; i <= n; i++)
        {
            string str;
            
            for (auto p: m)
            {
                if (i % p.first == 0)
                {
                    str += p.second;
                }
            }
            
            if (str.empty())
            {
                str = to_string(i);
            }
            
            res.push_back(str);
        }
        
        return res;
    }
};