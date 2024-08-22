#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> res;
bool visited[9];

void backtracking(int cnt) {
  if (cnt == M) {
    for (auto i : res) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      res.push_back(i);
      backtracking(cnt + 1);
      visited[i] = false;
      res.pop_back();
    }
  }
}

int main() {

  cin >> N >> M;
  backtracking(0);

  return 0;
}