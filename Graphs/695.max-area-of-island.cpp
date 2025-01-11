// @leet start
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    //dfs to keep calculate area of each island, after calculating area, keep track of the maximum area, when you calculate area of each island, remove the island so it doesnt get repeated

    int ans = 0;
    int count = 0;
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[0].size(); j++){
        if(grid[i][j] == 1){
          ans = max(ans, dfs(i, j, grid));
        }
      }
    }

    return ans;
  }

  int dfs(int i, int j, vector<vector<int>>& grid){
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
      return 0;
    }

    grid[i][j] = 0;

    int right = dfs(i+1, j, grid);
    int left = dfs(i-1, j, grid);
    int up = dfs(i, j+1, grid);
    int down = dfs(i, j-1, grid);

    return 1 + right + left + up + down;
  }
};
// @leet end
