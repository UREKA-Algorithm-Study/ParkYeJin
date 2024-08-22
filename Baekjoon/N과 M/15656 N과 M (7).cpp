#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> num;
vector<int> res;

void backtracking(int cnt) {
  if (cnt == M) {
    for (auto i : res) {
      cout << num[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    res.push_back(i);
    backtracking(cnt + 1);
    res.pop_back();
  }
}

int main() {

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    num.push_back(n);
  }
  sort(num.begin(), num.end());
  backtracking(0);

  return 0;
}