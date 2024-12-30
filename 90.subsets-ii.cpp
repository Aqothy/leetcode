// @leet start
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    //sort to prevent against duplicates
    sort(nums.begin(), nums.end());
    findSubsets(nums, 0, temp, ans);
    return ans;
  }

  void findSubsets(vector<int> &nums, int n, vector<int> &temp, vector<vector<int>> &ans){

    ans.push_back(temp);

    for(int i = n; i < nums.size(); i++){
      //skip duplicates
      if (i > n && nums[i] == nums[i - 1]) {
        continue;
      }
      temp.push_back(nums[i]);
      findSubsets(nums, i + 1, temp, ans);
      temp.pop_back();  
    }

  }
};
// @leet end
