/*
  492_v1.cpp
  Construct the Rectangle
*/

class Solution {
 public:
  vector<int> constructRectangle(int area) {
    vector<int> ret;
    int ub = (int)sqrt(1.0 * area);
    for (int i = ub; i >= 1; i--) {
      if (area % i == 0) {
        ret.push_back(area / i);
        ret.push_back(i);
        break;
      }
    }
    return ret;
  }
};