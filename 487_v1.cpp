/*
  487_v1.cpp
  Max Consecutive Ones II
*/

class Solution {
 public:
  int l[20000], r[20000];
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    l[0] = nums[0] == 1;
    r[n - 1] = nums[n - 1] == 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] == 1) {
        l[i] = l[i - 1] + 1;
      } else {
        l[i] = 0;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] == 1) {
        r[i] = r[i + 1] + 1;
      } else {
        r[i] = 0;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int val1 = (i - 1 >= 0 ? l[i - 1] : 0);
      int val2 = (i + 1 < n ? r[i + 1] : 0);
      if (nums[i] == 0) {
        ans = max(ans, val1 + val2 + 1);
      } else {
        ans = max(ans, l[i]);
        ans = max(ans, r[i]);
      }
    }
    return ans;
  }
};