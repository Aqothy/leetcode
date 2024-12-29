// @leet start
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    addSubset(nums, 0, temp, ans);
    return ans;
  }

  void addSubset(vector<int> &nums, int n, vector<int> &temp, vector<vector<int>> &ans){
    ans.push_back(temp); 
    for(int i = n; i < nums.size(); i++){
      temp.push_back(nums[i]);
      addSubset(nums, i + 1, temp, ans);
      temp.pop_back();
    }
  }
};
// @leet end
