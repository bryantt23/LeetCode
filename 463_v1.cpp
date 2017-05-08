/*
  463_v1.cpp
  Island Perimeter
*/

class Solution {
 public:
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int nRows, nCols;

  bool valid(int r, int c) {
    return 0 <= r && r < nRows && 0 <= c && c < nCols;
  }

  int islandPerimeter(vector<vector<int>>& grid) {
    nRows = grid.size();
    if (nRows == 0) {
      return 0;
    }
    nCols = grid[0].size();
    if (nCols == 0) {
      return 0;
    }
    int ans = 0;
    for (int i = 0; i < nRows; i++) {
      for (int j = 0; j < nCols; j++) {
        if (grid[i][j] == 1) {
          for (int k = 0; k < 4; k++) {
            int nr = i + dx[k], nc = j + dy[k];
            if (!valid(nr, nc) || grid[nr][nc] == 0) {
              ans++;
            }
          }
        }
      }
    }
    return ans;
  }
};
