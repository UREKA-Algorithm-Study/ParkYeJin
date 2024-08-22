#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> num;
vector<int> res;
bool visited[9];

void backtracking(int cnt, int pre) {
  if (cnt == M) {
    for (auto i : res) {
      cout << num[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = pre; i < N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      res.push_back(i);
      backtracking(cnt + 1, i);
      visited[i] = false;
      res.pop_back();
    }
  }
}

int main() {

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    int n;
    cin >> n;
    num.push_back(n);
  }
  sort(num.begin(), num.end());
  backtracking(0, 0);

  return 0;
}