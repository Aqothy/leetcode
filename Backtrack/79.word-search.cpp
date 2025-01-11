// @leet start
class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    //brute force dfs with backtrack to find all combinations I think???        
    //same letter may not be used more than once, so prob need to invalidate the letter after use by replacing it with like * or some special character, backtrack by putting char back
    //can go in all four directions so dfs in each direction
    //double for loop for checking the outcome of everysingle position
    for (int i = 0; i < board.size(); i++) {
      for (int k = 0; k < board[0].size(); k++) {    
        if(dfs(board, word, i, k, 0)){
          return true;
        }
      }
    }

    return false;
  }

  /**
   * @brief traverse throught the entire board
   *
   * @param board array of all the letters
   * @param word word that were looking for
   * @param m the row that were on 
   * @param n the col that were on
   * @param index the index of the letter were on in the word
   * @return bool
   */
  bool dfs(vector<vector<char>>& board, string word, int m, int n, int index){
    //need to keep track of which character you're on 
    //base case, when index == length of word, found the word, return
    if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] != word[index]) {
      return false;
    }

    if(index == word.size() - 1){
      return true;
    }

    //get rid of the char so it cant be used more than once
    char temp = board[m][n];
    board[m][n] = '*';

    bool left = dfs(board, word, m, n - 1, index + 1);
    bool right = dfs(board, word, m, n + 1, index + 1);
    bool up = dfs(board, word, m + 1, n, index + 1);
    bool down = dfs(board, word, m - 1, n, index + 1);

    //back track
    board[m][n] = temp;

    return left || right || up || down;
  } 
};
// @leet end
