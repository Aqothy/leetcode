// @leet start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    //combinations
    //store all the letters correponding to their number, easy way is to use hashmap, better is to use arrays
    if(digits.empty()){
      return {};
    }

    //hashmap to store the key and vals
    unordered_map<char, vector<char>> mp = {{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v', }}, {'9', {'w', 'x', 'y', 'z'}}};

    string temp;
    vector<string> ans;

    dfs(digits, temp, ans, mp, 0);

    return ans;

  }

  void dfs(string digits, string &temp, vector<string> &ans, unordered_map<char, vector<char>> &mp, int index){

    if(temp.size() == digits.size()){
      ans.push_back(temp);
    }

    for (int i = index; i < digits.size(); i++){
      for(auto &c : mp[digits[i]]){
        temp.push_back(c);
        dfs(digits, temp, ans, mp, i+1);
        temp.pop_back();
      }
    }
  }
};
// @leet end
