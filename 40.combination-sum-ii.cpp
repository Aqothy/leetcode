// @leet start
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // may only be used once, so basically the same as combination sum except you increment the starting index when going into another dfs        

    vector<int> temp;
    vector<vector<int>> ans;

    // using ideas from subset II, you can avoid duplicates by sorting and checking if the previous element is the same as the cur element
    sort(candidates.begin(), candidates.end());

    dfs(candidates, target, temp, ans, 0);

    return ans;
  }

  /**
   * @brief searches through all combinations and find the correct sum
   *
   * @param candidates the candidates
   * @param target target we trying to add up to
   * @param temp temp array to store the nums that add up to target
   * @param ans ans array
   * @param index the candidate were currently on
   */
  void dfs(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int index){

    if (target == 0){
      ans.push_back(temp);
      return;
    }

    if(target < 0){
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if(i > index && candidates[i] == candidates[i-1]){
        continue;
      }
      int can = candidates[i];
      int remain = target - can;
      temp.push_back(can);
      dfs(candidates, remain , temp, ans, i + 1);
      temp.pop_back();
    }
  }
};
// @leet end
