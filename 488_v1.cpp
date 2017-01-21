/*
  488_v1.cpp
  Zuma Game
*/

class Solution {
 public:
  string transform(string input, int idx, char ball) {
    string output = "";
    for (int i = 0; i < idx; i++) {
      output += input[i];
    }
    output += ball;
    for (int i = idx; i < input.size(); i++) {
      output += input[i];
    }
    bool flag = false;
    do {
      flag = false;
      string tmp = output;
      char curr = tmp[0];
      int cnt = 1, st = 0, en = 0;
      for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i] == curr) {
          cnt++;
        } else {
          if (cnt >= 3) {
            en = i - 1;
            flag = true;
            break;
          } else {
            cnt = 1, st = i, en = i, curr = tmp[i];
          }
        }
      }
      if (!flag && cnt >= 3) {
        en = tmp.size() - 1;
        flag = true;
      }
      if (flag) {
        output = "";
        for (int i = 0; i < st; i++) {
          output += tmp[i];
        }
        for (int i = en + 1; i < tmp.size(); i++) {
          output += tmp[i];
        }
      }
    } while (flag);
    return output;
  }

  int ans;

  set<pair<string, string>> m;

  void search(string curr, int numR, int numY, int numB, int numG, int numW,
              int numSteps) {
    string hand = "";
    for (int i = 0; i < numR; i++) hand += 'R';
    for (int i = 0; i < numY; i++) hand += 'Y';
    for (int i = 0; i < numB; i++) hand += 'B';
    for (int i = 0; i < numG; i++) hand += 'G';
    for (int i = 0; i < numW; i++) hand += 'W';

    pair<string, string> p = make_pair(curr, hand);
    if (m.find(p) != m.end()) {
      return;
    }

    m.insert(make_pair(curr, hand));

    if (curr == "") {
      ans = min(ans, numSteps);
      return;
    }
    for (int i = 0; i < curr.size(); i++) {
      if (numR && curr[i] == 'R')
        search(transform(curr, i, 'R'), numR - 1, numY, numB, numG, numW,
               numSteps + 1);
      if (numY && curr[i] == 'Y')
        search(transform(curr, i, 'Y'), numR, numY - 1, numB, numG, numW,
               numSteps + 1);
      if (numB && curr[i] == 'B')
        search(transform(curr, i, 'B'), numR, numY, numB - 1, numG, numW,
               numSteps + 1);
      if (numG && curr[i] == 'G')
        search(transform(curr, i, 'G'), numR, numY, numB, numG - 1, numW,
               numSteps + 1);
      if (numW && curr[i] == 'W')
        search(transform(curr, i, 'W'), numR, numY, numB, numG, numW - 1,
               numSteps + 1);
    }
  }

  int findMinStep(string board, string hand) {
    m.clear();
    ans = INT_MAX;
    int numR = 0, numY = 0, numB = 0, numG = 0, numW = 0;
    for (int i = 0; i < hand.size(); i++) {
      if (hand[i] == 'R')
        numR++;
      else if (hand[i] == 'Y')
        numY++;
      else if (hand[i] == 'B')
        numB++;
      else if (hand[i] == 'G')
        numG++;
      else
        numW++;
    }
    search(board, numR, numY, numB, numG, numW, 0);
    if (ans == INT_MAX) {
      return -1;
    }
    return ans;
  }
};