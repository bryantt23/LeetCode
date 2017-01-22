/*
  494_v1.cpp
  Target Sum

  My first submission failed because my O(2^n * n) brute-force algorithm
  received a TLE. My second submission got WA because initially I wrote
  this:

  m[0].insert(make_pair(nums[0], 1));
  m[0].insert(make_pair(-nums[0], 1));

  The above code has a bug where nums[0] == 0.
*/

class Solution {
 public:
  map<int, int> m[20];
  int findTargetSumWays(vector<int>& nums, int S) {
    for (int i = 0; i < 20; i++) {
      m[i].clear();
    }
    int n = nums.size(), ans = 0;
    m[0][nums[0]]++;
    m[0][-nums[0]]++;
    for (int i = 1; i < n; i++) {
      for (auto p : m[i - 1]) {
        int newVal = p.first + nums[i];
        m[i][newVal] += p.second;
        newVal = p.first - nums[i];
        m[i][newVal] += p.second;
      }
    }
    return m[n - 1][S];
  }
};