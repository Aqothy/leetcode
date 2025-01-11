// @leet start
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    // bfs, loop through all the orange and if the orange is rotten then bfs through it

    //directions, can when loop can just do {i, i+1}, where i is x and i+1 is y
    int dir[5] = {-1, 0, 1, 0, -1};
    //pairs of coordinates
    queue<pair<int, int>> q;

    int fresh = 0;
    //double for loop to precompute everything
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        // if orange is rotten, push onto stack, else if its fresh, keep track of it and if at the end there are still fresh oranges return -1
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1){
          fresh++; 
        } 
      }
    }

    int min = -1;
    //start bfs
    while(!q.empty()){
      int sz=q.size();
      while(sz--){
        auto [x, y] = q.front();
        q.pop();
        //go in all 4 directions
        for (int i = 0; i < 4; i++) {
          int newX = x + dir[i];
          int newY = y + dir[i+1];
          if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 1){
            //make the ornage rotten
            grid[newX][newY] = 2;
            //push onto stack
            q.push({newX, newY});
            fresh--;
          }
        }
      }
      //after all all 4 directions, 1 min has passed
      min++;
    }

    return fresh == 0 ? (min == -1 ? 0 : min) : -1;
  }

};
// @leet end
