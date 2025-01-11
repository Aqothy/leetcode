// @leet start
class Solution {
public:
  void solve(vector<vector<char>>& board) {
    //key important hint here is that *none of the region cells are on the edge of the board.        
    //using this clue, we can check if the edges have any Os and if the Os connect to any of the Os that are not on the edge and those Os will not be surrounded. Instead of Os we chnage them to another place holder to indicate that you dont surround them, for example can use like N or 
    int m = board.size();
    int n = board[0].size();
    //check all the column edges
    for (int r = 0; r < m; r++) {
      if (board[r][0] == 'O') {
        capture(board, r, 0);
      }
      if (board[r][n - 1] == 'O') {
        capture(board, r, n - 1);
      }
    }

    for (int c = 0; c < n; c++) {
      if (board[0][c] == 'O') {
        capture(board, 0, c);
      }
      if (board[m - 1][c] == 'O') {
        capture(board, m - 1, c);
      }
    }

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (board[r][c] == 'O') {
          board[r][c] = 'X';
        } else if (board[r][c] == 'N') {
          board[r][c] = 'O';
        }
      }
    }
  }

  void capture(vector<vector<char>>& board, int i, int j){
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O'){
      return;
    }

    board[i][j] = 'N';
    //go 4 directionally
    capture(board, i+1, j);
    capture(board, i-1, j);
    capture(board, i, j+1);
    capture(board, i, j-1);
  }
};
// @leet end
