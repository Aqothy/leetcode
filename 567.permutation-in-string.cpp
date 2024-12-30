// @leet start
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    //can use array or hashmap to keep track of the character count, could be a sliding window problem???
    vector<int> mp1(26, 0);
    vector<int> mp2(26, 0);
    for (char &c : s1){
      mp1[c - 'a']++;
    }

    // compare the size with the pointer interval to check if s2 contains permutation of s1
    int n = s1.size();
  
    //left pointer 
    int left = 0;
    for(int right = 0; right < s2.size(); right++){
      mp2[s2[right] - 'a']++;
      if(n == right - left + 1){
        if(mp1 == mp2){
          return true;
        } else {
          //shrink the window, which is just removing the left most character
          mp2[s2[left] - 'a']--;
          //inc left
          left++;
        }
      } 
    }

    return false;
  }
};
// @leet end
