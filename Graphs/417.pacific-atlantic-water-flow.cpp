// @leet start
class Solution {
public:

  vector<int> dir = {-1, 0, 1, 0, -1};

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    //first intuition is going through every single square and checking, then running 2 dfs, one to the pacific and the other ot the atlantic ocean, for pacific dfs it can only go up or left and for atlantic it can only go right or down
    //well after thinking it can actually go in all four directions and still reach pacific / atlantic so yeah...
    // solution is start from and the edge meaning that is guaranteed to get into the ocean and see what grids we make it too, it seems like a lot of these graph problems use these kinda clever backwards approach so need to keep it in mind for the future

    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> pacific(m, vector<int>(n, 0));
    vector<vector<int>> atlantic(m, vector<int>(n, 0));
    vector<vector<int>> ans;

    //first loop through the left and right columns
    for (int i = 0; i < m; i++) {
      //left col
      dfs(heights, pacific, i, 0);
      //right col
      dfs(heights, atlantic, i, n - 1);
    }

    for (int j = 0; j < n; j++) {
      dfs(heights, pacific, 0, j);       // Top row
      dfs(heights, atlantic, m - 1, j); // Bottom row
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if(pacific[i][j] && atlantic[i][j]){
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }

  void dfs(vector<vector<int>>& heights, vector<vector<int>> &visited, int i, int j){

    visited[i][j] = 1;

    for (int d = 0; d < 4; d++) {
      int ni = i + dir[d];     // Compute the new row index
      int nj = j + dir[d + 1]; // Compute the new column index
      // Guard condition for bounds and validity
      if (ni >= 0 && ni < heights.size() && 
        nj >= 0 && nj < heights[0].size() && 
        !visited[ni][nj] && 
        heights[ni][nj] >= heights[i][j]) {
        dfs(heights, visited, ni, nj);
      }
    }
  }
};
// @leet end
