/*
  560_v1.cpp
  Subarray Sum Equals K
*/

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    map<long long, long long> m;
    m[0] = 1;
    long long curr = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      curr += nums[i];
      if (m.count(curr - k)) {
        ans += m[curr - k];
      }
      m[curr]++;
    }
    return ans;
  }
};
