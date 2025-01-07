// @leet start
class Solution {
public:
  vector<vector<string>> partition(string s) {
    //a string is a palindrome when it is the same forwards and backwards, we know every single letter will be a palindrome, that is a guarantee answer

    //brute force way would just to check for every partition, is it a palindrome

    vector<string> par;
    vector<vector<string>> ans;
    dfs(s, par, ans, 0);

    return ans;
  }

  void dfs(string s, vector<string> &par, vector<vector<string>> &ans, int index){
    int n = s.size();
    if(n == index){
      ans.push_back(par);
      return;
    }

    for(int i = index; i < n; i++){
      if(isPal(s, index, i)){
        par.push_back(s.substr(index, i - index + 1));
        dfs(s, par, ans, i + 1);
        par.pop_back();
      }
    }
  }

  //helper function to s if the parition is palindrome
  bool isPal(string s, int start, int end){
    while(start < end){
      if(s[start++] != s[end--]){
        return false;
      }
    }
    return true;
  }
};
// @leet end
