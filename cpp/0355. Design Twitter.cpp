// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

// postTweet(userId, tweetId): Compose a new tweet.
// getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
// follow(followerId, followeeId): Follower follows a followee.
// unfollow(followerId, followeeId): Follower unfollows a followee.
// Example:

// Twitter twitter = new Twitter();

// // User 1 posts a new tweet (id = 5).
// twitter.postTweet(1, 5);

// // User 1's news feed should return a list with 1 tweet id -> [5].
// twitter.getNewsFeed(1);

// // User 1 follows user 2.
// twitter.follow(1, 2);

// // User 2 posts a new tweet (id = 6).
// twitter.postTweet(2, 6);

// // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.getNewsFeed(1);

// // User 1 unfollows user 2.
// twitter.unfollow(1, 2);

// // User 1's news feed should return a list with 1 tweet id -> [5],
// // since user 1 is no longer following user 2.
// twitter.getNewsFeed(1);


class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert({cnt++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        map<int, int> top10;//time tweetId
        
        for (auto id: friends[userId])
        {
            for (auto t: tweets[id])
            {                    
                top10.insert(t);
                if (top10.size() > 10)
                    top10.erase(top10.begin());
            }
        }
        
        vector<int> res;
        for (auto m = top10.rbegin(); m != top10.rend(); ++m)
            res.push_back(m->second);
            
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            friends[followerId].erase(followeeId);
    }
    
    int cnt;
    unordered_map<int, set<int>> friends;//id id
    unordered_map<int, map<int, int>> tweets;//id time tweetId
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */