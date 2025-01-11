// @leet start
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    //dfs, after finding 1s, change them to 0 to skip searching them again thus improving efficiency

    int numIslands = 0;
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[0].size(); j++){
        if(grid[i][j] == '1'){
          numIslands++;
          dfs(grid, i, j);
        }
      }
    }

    return numIslands;
  }

  void dfs(vector<vector<char>>& grid, int m, int n){
    //go in all 4 directions
    // check for out of bounds
    if (m < 0 || m >= grid.size() || n < 0 || n >= grid[0].size() || grid[m][n] == '0'){
      return;
    }

    grid[m][n] = '0';

    dfs(grid, m+1, n); //down
    dfs(grid, m-1, n); //up
    dfs(grid, m, n+1); //right
    dfs(grid, m, n-1); //left
  }
};
// @leet end
