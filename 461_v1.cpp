/*
  461_v1.cpp
  Hamming Distance
*/

class Solution {
 public:
  int hammingDistance(int x, int y) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      int v1 = x & (1 << i);
      int v2 = y & (1 << i);
      if (v1 != v2) {
        ans++;
      }
    }
    return ans;
  }
};
