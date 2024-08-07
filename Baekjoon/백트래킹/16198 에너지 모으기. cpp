#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, res = 0;
vector<int> v;

void energy(int sum) {
  if (v.size() == 2) {
    res = max(res, sum);
    return;
  }
  for (int i = 1; i < v.size() - 1; i++) {
    int add = v[i - 1] * v[i + 1];
    int tmp = v[i];

    v.erase(v.begin() + i);
    energy(sum + add);
    v.insert(v.begin() + i, tmp);
  }
}

int main() {
  cin >> N;

  int w;
  for (int i = 0; i < N; i++) {
    cin >> w;
    v.push_back(w);
  }
  energy(0);
  cout << res;

  return 0;
}