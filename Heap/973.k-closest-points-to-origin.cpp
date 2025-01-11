// @leet start
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //calculate the distance, keep track in a vector of pair that is int and vectora, sort the vector and return k elements
    // sorting will work since if the elements are pairs then it sorts by the first element of the pair

    int n = points.size();
    vector<pair<int, vector<int>>> res(n);

    for (int i = 0; i < n; i++){
      int x = points[i][0];
      int y = points[i][1];
      int squaredDistance = x * x + y * y;
      res[i] = {squaredDistance, points[i]};
    }

    sort(res.begin(), res.end());
    vector<vector<int>> ans(k);
    for(int i = 0; i < k; i++){
      ans[i] = res[i].second;
    }

    return ans;
  }
};
// @leet end
