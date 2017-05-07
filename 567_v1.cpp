/*
  567_v1.cpp
  Permutation in String
*/

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size()) {
      return false;
    }

    int c[26];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < s1.size(); i++) {
      c[s1[i] - 'a']++;
    }

    for (int i = 0; i < s1.size(); i++) {
      c[s2[i] - 'a']--;
    }
    int idx = 0;
    while (true) {
      bool valid = true;
      for (int i = 0; i < 26; i++) {
        if (c[i]) {
          valid = false;
          break;
        }
      }
      if (valid) {
        return true;
      }
      c[s2[idx] - 'a']++;
      if (idx + s1.size() < s2.size()) {
        c[s2[idx + s1.size()] - 'a']--;
      } else {
        break;
      }
      idx++;
    }
    return false;
  }
};
