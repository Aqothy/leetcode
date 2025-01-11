// @leet start
class Twitter {

public:
  //time each post was created
  int time;
  //keep track of the user followings
  unordered_map<int, set<int>> following;
  //<userid, {count, tweetId}>
  unordered_map<int, vector<pair<int, int>>> tweets;

  Twitter() {
    time = 0;
  }

  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back({time, tweetId});
    time++;
  }

  vector<int> getNewsFeed(int userId) {

    vector<int> res;
    //max heap to keep track of the most recent post
    priority_queue<pair<int, int>> newsFeed;
    for (auto &tweet : tweets[userId]){
      newsFeed.push(tweet);
    }
    for (auto &uid : following[userId]){
      for (auto &tweet : tweets[uid]){
        newsFeed.push(tweet);
      }
    }

    while(!newsFeed.empty()){
      if(res.size() == 10) break;
      res.push_back(newsFeed.top().second);
      newsFeed.pop();
    }

    return res;
  }

  void follow(int followerId, int followeeId) {
    if (followerId != followeeId){  
      following[followerId].insert(followeeId); 
    }
  }

  void unfollow(int followerId, int followeeId) {
    if (following[followerId].find(followeeId) != following[followerId].end()){
      following[followerId].erase(followeeId);
    }
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @leet end
