/*
  491_v1.cpp
  Increasing Subsequences
*/

class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> ans;
    for (int i = 0; i < (1 << n); i++) {
      vector<int> tmp;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          tmp.push_back(nums[j]);
        }
      }
      if (tmp.size() >= 2) {
        bool flag = true;
        for (int j = 1; j < tmp.size(); j++) {
          if (tmp[j] < tmp[j - 1]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          ans.insert(tmp);
        }
      }
    }
    vector<vector<int>> ret;
    for (vector<int> v : ans) {
      ret.push_back(v);
    }
    return ret;
  }
};