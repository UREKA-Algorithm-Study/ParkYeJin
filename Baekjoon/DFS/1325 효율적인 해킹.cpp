#include <bits/stdc++.h>
using namespace std;

vector <int> v[10001];
bool visited[10001];

int dfs(int n){
  int cnt = 1;
  visited[n] = true;
  for(int i = 0; i < v[n].size(); i++){
    if (!visited[v[n][i]]) {
      cnt += dfs(v[n][i]);
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int from, to;
    cin >> from >> to;
    v[to].push_back(from);
  }

  vector <pair<int, int>> res; // 해킹수, 컴퓨터의 번호
  int maxNum = 0;
  for(int i = 1; i <= N; i++){
    memset(visited, 0, sizeof(visited));

    int num = dfs(i);
    res.push_back({num, i});
    maxNum = max(maxNum, num);
  }
  sort(res.rbegin(), res.rend());
  
  // 컴퓨터의 번호 오름차순
  vector <int> c;
  for(auto iter : res) {
    if (maxNum == iter.first) {
      c.push_back(iter.second);
    }
  }
  sort(c.begin(), c.end());
  for(auto iter : c) cout << iter << " ";

  return 0;
} 