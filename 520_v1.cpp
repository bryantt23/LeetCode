/*
  520_v1.cpp
  Detect Capital
*/

class Solution {
 public:
  bool detectCapitalUse(string word) {
    bool ans;
    int cnt_upper = 0, cnt_lower = 0, upperIdx = -1;
    for (int i = 0; i < word.size(); i++) {
      if (isupper(word[i])) {
        cnt_upper++;
        upperIdx = i;
      } else {
        cnt_lower++;
      }
    }
    return (cnt_upper == word.size() || cnt_lower == word.size() ||
            (cnt_upper == 1 && upperIdx == 0));
  }
};
