// Alice plays the following game, loosely based on the card game "21".

// Alice starts with 0 points, and draws numbers while she has less than K points.  During each draw, she gains an integer number of points randomly from the range [1, W], where W is an integer.  Each draw is independent and the outcomes have equal probabilities.

// Alice stops drawing numbers when she gets K or more points.  What is the probability that she has N or less points?

// Example 1:

// Input: N = 10, K = 1, W = 10
// Output: 1.00000
// Explanation:  Alice gets a single card, then stops.
// Example 2:

// Input: N = 6, K = 1, W = 10
// Output: 0.60000
// Explanation:  Alice gets a single card, then stops.
// In 6 out of W = 10 possibilities, she is at or below N = 6 points.
// Example 3:

// Input: N = 21, K = 17, W = 10
// Output: 0.73278
// Note:

// 0 <= K <= N <= 10000
// 1 <= W <= 10000
// Answers will be accepted as correct if they are within 10^-5 of the correct answer.
// The judging time limit has been reduced for this question.


class Solution {
public:
    double new21Game(int N, int K, int W) {
        // 0    K-W     K-1 K K+1   K+W     N
        // 0    K-W     K-1 K K+1           N     K+W
        double dp[N + W + 1] = {0.0};
        
        for (int i = K; i <= N; i++)
        {
            dp[i] = 1.0;
        }
        
        double sum = min(W, N - K + 1);
        for (int i = K - 1; i >= 0; i--)
        {
            // sum = dp[i+1] + dp[i+2] + ... + dp[i+W]
            // 即i位置发牌后成功的总概率和
            dp[i] = sum / W;
            sum += dp[i] - dp[i + W]; // 向前移动窗口
        }
        
        return dp[0];
    }
};
