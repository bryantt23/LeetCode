/*
  486_v1.cpp
  Predict the Winner

  My first submission got WA simply because I overlooked this sentence: >_<
  "If the scores of both players are equal, then player 1 is still the winner."
*/

class Solution {
 public:
  int f[25][25];
  int solve(vector<int>& nums, int l, int r) {
    if (f[l][r] != -1) {
      return f[l][r];
    }
    if (l == r) {
      return f[l][r] = nums[l];
    }
    if (l + 1 == r) {
      return f[l][r] = max(nums[l], nums[r]);
    }
    int ans1 = nums[l] + min(solve(nums, l + 2, r), solve(nums, l + 1, r - 1));
    int ans2 = nums[r] + min(solve(nums, l + 1, r - 1), solve(nums, l, r - 2));
    return f[l][r] = max(ans1, ans2);
  }
  bool PredictTheWinner(vector<int>& nums) {
    memset(f, -1, sizeof(f));
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    int ans1 = solve(nums, 0, nums.size() - 1);
    int ans2 = sum - ans1;
    return ans1 >= ans2;
  }
};