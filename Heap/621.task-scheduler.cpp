// @leet start
class Solution {
  typedef pair<int, int> pa;
public:
  int leastInterval(vector<char>& tasks, int n) {
    //should probably start with the most frequent task, you want to get that out of the way first
    //find the most frequent task by tracking it with a hashmap

    unordered_map<char, int> mp;
    for (char &task : tasks){
      mp[task]++;
    }

    //keep track of the current time
    int time = 0;

    priority_queue<int> pq; 

    for (auto &p : mp){
      pq.push(p.second);
    }

    queue<pa> q;

    while(!pq.empty() || !q.empty()){
      time++;
      if(!pq.empty()){
        int task = pq.top();
        pq.pop();
        if(task > 1){
          q.push({task - 1, time + n});   
        }
      }
      if(!q.empty() && time == q.front().second){
        int newTask = q.front().first;
        pq.push(newTask);
        q.pop();
      }
    }

    return time; 

  }
};
// @leet end
