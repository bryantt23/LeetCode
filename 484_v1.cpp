/*
  484_v1.cpp
  Find Permutation

  This problem took me a long time during the contest. My first
  submission uses a greedy approach. I tried to assign 1 to the
  first integer and then increment or decrement the following
  integers based on the input string. I also use a set to ensure
  I do not use any duplicate integers. Then I create a permutation
  by shifting the minimum integer in this sequence to 1.

  I don't know why but this approach looked quite promising to me
  during the contest. But it fails on even the simplest test case
  I could come up with: "IID". Apparently the answer should be
  1243. But my algorithm would come up with 1230 and then the whole
  sequence get shifted by 2341.

  Therefore, my first submission undoubtedly get a WA. I then came
  up with this approach by construction and guessing. Later I've
  checked the solutions of other people and I've seen some other
  algorithms utilizing topological sorting, which is natural and
  I blame myself not able to come up with ideas like that during
  the contest.
*/

class Solution {
 public:
  vector<int> findPermutation(string s) {
    vector<int> ans;
    for (int i = 1; i <= s.size() + 1; i++) {
      ans.push_back(i);
    }
    int st = -1, en = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'D') {
        if (st == -1) {
          st = i;
        }
        en = i;
      } else {
        if (en != -1) {
          reverse(ans.begin() + st, ans.begin() + en + 2);
        }
        st = en = -1;
      }
    }
    if (en != -1) {
      reverse(ans.begin() + st, ans.begin() + en + 2);
    }
    return ans;
  }
};