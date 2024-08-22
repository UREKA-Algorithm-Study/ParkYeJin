#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> res;
bool visited[9];

void backtracking(int cnt, int pre) {
  if (cnt == M) {
    for (auto i : res) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = pre; i <= N; i++) {
    res.push_back(i);
    backtracking(cnt + 1, i);
    res.pop_back();
  }
}

int main() {

  cin >> N >> M;
  backtracking(0, 1);

  return 0;
}