/*
  383_v1.cpp
  Ransom Note

  My first submission got WA since I forgot to memset the two arrays...
*/

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int a[256], b[256];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < ransomNote.size(); i++) {
      a[ransomNote[i]]++;
    }
    for (int i = 0; i < magazine.size(); i++) {
      b[magazine[i]]++;
    }
    bool flag = true;
    for (int i = 0; i < 256; i++) {
      if (a[i] > b[i]) {
        flag = false;
        break;
      }
    }
    return flag;
  }
};