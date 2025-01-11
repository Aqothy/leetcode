// @leet start
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> res;
    // Start recursion with index 0 and target value
    combination(candidates, target, temp, res, 0);
    return res;
  }

  void combination(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& res, int start) {
    // Base case: when target is met, add the current combination to the result
    if (target == 0) {
      res.push_back(temp);
      return;
    }

    // If target becomes negative, stop exploration
    if (target < 0) {
      return;
    }

    // Explore each candidate starting from the current index
    for (int i = start; i < candidates.size(); i++) {
      temp.push_back(candidates[i]); // Add candidate to the current combination
      combination(candidates, target - candidates[i], temp, res, i); // Recurse with updated target
      temp.pop_back(); // Backtrack
    }
  }
};
// @leet end
