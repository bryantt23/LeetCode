/*
  573_v1.cpp
  Squirrel Simulation
*/

class Solution {
 public:
  int minDistance(int height, int width, vector<int>& tree,
                  vector<int>& squirrel, vector<vector<int>>& nuts) {
    vector<int> nd, sd;
    int sum = 0;
    for (int i = 0; i < nuts.size(); i++) {
      int tmp = abs(nuts[i][0] - tree[0]) + abs(nuts[i][1] - tree[1]);
      sum += tmp;
      nd.push_back(tmp);
      sd.push_back(abs(nuts[i][0] - squirrel[0]) +
                   abs(nuts[i][1] - squirrel[1]));
    }
    int ans = -1;
    for (int i = 0; i < nuts.size(); i++) {
      int tmp = sum * 2 - nd[i] + sd[i];
      if (ans == -1 || tmp < ans) {
        ans = tmp;
      }
    }
    return ans;
  }
};