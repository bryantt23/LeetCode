/*
  476_v1.cpp
  Number Complement
*/

class Solution {
 public:
  int findComplement(int num) {
    int ans = 0, cnt = 0;
    while (num) {
      if (num % 2 == 0) {
        ans |= (1 << cnt);
      }
      num /= 2;
      cnt++;
    }
    return ans;
  }
};
