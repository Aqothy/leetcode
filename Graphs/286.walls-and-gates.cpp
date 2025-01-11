// leetcode premium question
// You are given a
// m
// ×
// n
// m×n 2D grid initialized with these three possible values:
//
// -1 - A water cell that can not be traversed.
// 0 - A treasure chest.
// INF - A land cell that can be traversed. We use the integer 2^31 - 1 =
// 2147483647 to represent INF. Fill each land cell with the distance to its
// nearest treasure chest. If a land cell cannot reach a treasure chest than the
// value should remain INF.
//
// Assume the grid can only be traversed up, down, left, or right.
//
// Modify the grid in-place.
//
// Input: [
//   [2147483647,-1,0,2147483647],
//   [2147483647,2147483647,2147483647,-1],
//   [2147483647,-1,2147483647,-1],
//   [0,-1,2147483647,2147483647]
// ]
//
// Output: [
//   [3,-1,0,1],
//   [2,2,1,-1],
//   [1,-1,2,-1],
//   [0,-1,3,4]
// ]
//
// Input: [
//   [0,-1],
//   [2147483647,2147483647]
// ]
//
// Output: [
//   [0,-1],
//   [1,2]
// ]

class Solution {
public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    // instead of starting from the INF and brute force dfs back track to get to
    // the gate, start from the gate and then bfs from, updating the layer each
    // time by 1, neat thing about this is that bfs guarantees that the path
    // found will be the shortest since you visit it layer by layer accounts for
    // all 4 directions
    vector<int> dir = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        // if its a gate, add to q
        if (grid[i][j] == 0) {
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      int n = q.front().first;
      int m = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int x = n + dir[i];
        int y = m + dir[i + 1];
        // int max is same as inf, if its not inf, it means its another gate or
        // the shortest path has already been found, or if its out of bounds
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
            grid[x][y] != INT_MAX) {
          continue;
        }
        grid[x][y] = grid[n][m] + 1;
        q.push({x, y});
      }
    }
  }
};
