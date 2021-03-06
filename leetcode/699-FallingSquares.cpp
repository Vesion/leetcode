#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int n;
  vector<int> height, lazy;

  void push_up(int i) {
    height[i] = max(height[i*2], height[i*2+1]);
  }

  void push_down(int i) {
    if (lazy[i]) {
        lazy[i*2] = lazy[i*2+1] = lazy[i];
        height[i*2] = height[i*2+1] = lazy[i];
        lazy[i] = 0;
    }
  }

  void update(int i, int l, int r, int L, int R, int val) {
    if (L <= l && r <= R) {
      height[i] = val;
      lazy[i] = val;
      return;
    }
    push_down(i);
    int mid = l + (r-l)/2;
    if (L < mid) update(i*2, l, mid, L, R, val);
    if (R > mid) update(i*2+1, mid, r, L, R, val);
    push_up(i);
  }

  int query(int i, int l, int r, int L, int R) {
    if (L <= l && r <= R) return height[i];
    push_down(i);
    int res = 0;;
    int mid = l + (r-l)/2;
    if (L < mid) res = max(res, query(i*2, l, mid, L, R));
    if (R > mid) res = max(res, query(i*2+1, mid, r, L, R));
    return res;
  }

  vector<int> fallingSquares(vector<pair<int, int>>& positions) {
    vector<int> a;
    for (auto& p : positions) {
      a.push_back(p.first);
      a.push_back(p.first+p.second);
    }
    sort(a.begin(), a.end());
    n = unique(a.begin(), a.end()) - a.begin();
    a.resize(n);
    
    height.resize(n<<2, 0);
    lazy.resize(n<<2, 0);
    vector<int> res;
    for (auto& p : positions) {
      int l = lower_bound(a.begin(), a.end(), p.first) - a.begin();
      int r = lower_bound(a.begin(), a.end(), p.first+p.second) - a.begin();
      int maxh = query(1, 0, n, l, r);
      update(1, 0, n, l, r, maxh+p.second);
      res.push_back(query(1, 0, n, 0, n));
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<pair<int,int>> p = {{1,2}, {2,3}, {6,1}};
  //vector<pair<int,int>> p = {{100,100}, {300,100}, {200,100}};
  //vector<pair<int,int>> p = {{9,7}, {1,9}, {3,1}};
  auto r = s.fallingSquares(p);
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
