/*
  575_v1.cpp
  Distribute Candies
*/

class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    set<int> s;
    for (auto& c : candies) {
      s.insert(c);
    }
    return min(s.size(), candies.size() / 2);
  }
};
