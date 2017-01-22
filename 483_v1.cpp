/*
  483_v1.cpp
  Smallest Good Base

  I spent a lot of time debugging this problem during the contest.

  The underlying idea is trivial but since the numbers can overflow
  I need a way to check overflow before actually "overflowing" the
  number.

  The "if ((LLONG_MAX - 1) / mid < val" part is correct. However,
  in my first implementation I wrote something like this:

  for (int j = 0; j < i; j++) {
    val = val * mid + 1;
    if ((LLONG_MAX - 1) / mid < val) {
        val = LLONG_MAX;
        break;
    }
  }

  It's easy to see where the issue is right now but during the contest
  it took a fairly long time for me to figure out this issue. My first
  submission got WA because of this.
*/

class Solution {
 public:
  string smallestGoodBase(string _n) {
    long long n = 0;
    for (int i = 0; i < _n.size(); i++) {
      n = n * 10 + (_n[i] - '0');
    }
    long long ans = LLONG_MAX;
    for (int i = 2; i <= 63; i++) {
      long long l = 2, r = n, mid;
      // [l, r]
      while (l <= r) {
        mid = (l + r) >> 1;
        long long val = 0;
        for (int j = 0; j < i; j++) {
          if ((LLONG_MAX - 1) / mid < val) {
            val = LLONG_MAX;
            break;
          }
          val = val * mid + 1;
        }
        if (val > n) {
          r = mid - 1;
        } else if (val == n) {
          ans = min(ans, mid);
          break;
        } else {
          l = mid + 1;
        }
      }
    }
    return to_string(ans);
  }
};