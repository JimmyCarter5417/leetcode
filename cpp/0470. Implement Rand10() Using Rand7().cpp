// Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

// Do NOT use system's Math.random(). 

// Example 1:
// Input: 1
// Output: [7]

// Example 2:
// Input: 2
// Output: [8,4]

// Example 3:
// Input: 3
// Output: [8,1,10] 

// Note:
// rand7 is predefined.
// Each testcase has one argument: n, the number of times that rand10 is called.
 

// Follow up:
// What is the expected value for the number of calls to rand7() function?
// Could you minimize the number of calls to rand7()?


// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// solution I: 拒绝采样
class Solution {
public:
    int rand10() {
        // (RandN - 1) % 10 + 1，可以求出Rand10，当N是10的倍数的时候。
        // (Rand7 - 1) * 7 + Rand7，可以随机生成1-49，记作Rand49。
        // 拒绝采样：用Rand49生成一个数，如果它位于41-49，则丢弃，继续生成，当生成一个1-40的数时返回。这样子做可以近似看成随机生成1-40之间的数。

        // 生成任意随机数原理如下：
        // rand2() - 1 + rand()2  =   ?
        //    1            1          1
        //    1            2          2
        //    2            1          2
        //    2            2          3
        // （rand2() - 1） * 2 + rand()2  =   ?
        //      1                  1         1
        //      1                  2         2
        //      2                  1         3
        //      2                  2         4
        while (1)
        {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40)
            {
                return num % 10 + 1;
            }
        }
        
        return 0; // impossible
    }
};

// solution II: 拒绝采样-优化
class Solution {
public:
    int rand10() {
        while (true) {
            int a = rand7(); // rand7
            int num = (a - 1) * 7 + rand7(); // rand49

            if (num <= 40) 
                return num % 10 + 1;

            a = num - 40; // rand9
            num = (a - 1) * 7 + rand7(); // rand63
            if (num <= 60) 
                return num % 10 + 1;

            a = num - 60; // rand3
            num = (a - 1) * 7 + rand7(); // rand21
            if (num <= 20) 
                return num % 10 + 1;
            else
                ; // 只有得到21才需要循环，大大降低了需要循环的概率
        }

        return 0; // impossible
    }
};