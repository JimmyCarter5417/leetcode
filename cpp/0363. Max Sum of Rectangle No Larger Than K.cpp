// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

// Example:

// Given matrix = [
//   [1,  0, 1],
//   [0, -2, 3]
// ]
// k = 2 

// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

// Note:

// The rectangle inside the matrix must have an area > 0.
// What if the number of rows is much larger than the number of columns? 

// Credits:
// Special thanks to @fujiaozhu for adding this problem and creating all test cases.



// 类似问题：
//
// 求最大子矩阵和
// http://www.cnblogs.com/grandyang/p/5487815.html
// https://www.youtube.com/watch?v=yCQN096CwWM
//
// 0053. Maximum Subarray
// 0325. Maximum Size Subarray Sum Equals k

// 写起来太麻烦了，先记下思路
// 1、累加数组：方便计算各个子矩阵和
// 2、记录每一行部分和：具体方法见上面的油管链接
// 3、处理部分和：使用Maximum Subarray的方法，部分和的子数组，就是要求的“子矩阵”；只是不需要记录最大和，而是最接近K的和