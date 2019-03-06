//Given a list of non negative integers, arrange them such that they form the largest number.
//
//Example 1:
//Input: [10,2]
//Output: "210"
//
//Example 2:
//Input: [3,30,34,5,9]
//Output: "9534330"
//
//Note: The result may be very large, so you need to return a string instead of an integer.
//


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), 
             [](int n1, int n2)
             {
                 string str1 = to_string(n1);
                 string str2 = to_string(n2);
                 return  str1 + str2 > str2 + str1; // 关键在于自定义排序方法
             });
        
        if (nums[0] == 0) // 全0就没必要再拼装了
        {
            return "0";
        }
        
        for (int n: nums)
        {
            res += to_string(n);
        }
        
        return res;
    }
};

