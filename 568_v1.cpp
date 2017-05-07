/*
  568_v1.cpp
  Maximum Vacation Days
*/

class Solution {
 public:
  int f[101][101];  // city i, week j
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    int n = days.size(), k = days[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        f[i][j] = -1;
      }
    }
    f[0][0] = days[0][0];
    for (int i = 1; i < n; i++) {
      if (flights[0][i]) {
        f[i][0] = days[i][0];
      }
    }
    for (int i = 1; i < k; i++) {
      for (int j = 0; j < n; j++) {
        int tmp;
        if (f[j][i - 1] != -1) {
          tmp = f[j][i - 1] + days[j][i];
        } else {
          tmp = -1;
        }
        for (int k = 0; k < n; k++) {
          if (j == k) {
            continue;
          } else {
            if (flights[k][j] && f[k][i - 1] != -1) {
              tmp = max(tmp, f[k][i - 1] + days[j][i]);
            }
          }
        }
        f[j][i] = tmp;
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, f[i][k - 1]);
    return ans;
  }
};
