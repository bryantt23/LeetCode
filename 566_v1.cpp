/*
  566_v1.cpp
  Reshape the Matrix
*/

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    vector<vector<int>> ret;
    int row = nums.size();
    if (row == 0) {
      return nums;
    }
    int col = nums[0].size();
    if (r * c != row * col) {
      return nums;
    }
    vector<int> v;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        v.push_back(nums[i][j]);
      }
    }
    int ptr = 0;
    for (int i = 0; i < r; i++) {
      vector<int> tmp;
      for (int j = 0; j < c; j++) {
        tmp.push_back(v[ptr++]);
      }
      ret.push_back(tmp);
    }
    return ret;
  }
};
