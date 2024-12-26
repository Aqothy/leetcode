// @leet start
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    //kth largest element, it is sorted so you can either sort in descending order or you can just use a min heap and then return the kth element
    //sort by descending order
    /*sort(nums.begin(), nums.end(), [](int a, int b){*/
    /*  return b < a;*/
    /*});*/
    /**/
    /*return nums[k-1];*/

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int n : nums) {
      pq.push(n);
      if (pq.size() > k) {
        pq.pop(); // Maintain heap size of k
      }
    }

    // The root of the min-heap is the Kth largest element
    return pq.top();
  }
};
// @leet end
