#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/*
  이동하려는 방 숫자 = 현재 방 숫자 + 1
*/

int N, arr[1001][1001];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int res = 0;
void dfs(int x, int y, int depth){
  res = max(res, depth);

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
    if (arr[nx][ny] - arr[x][y] == 1) {
      dfs(nx, ny, depth + 1);
    }
  }
}

bool cmp(pair <int, int> &p1, pair <int, int> &p2){
  if (p1.first == p2.first) return p1.second < p2.second;
  else return p1.first > p2.first;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    res = 0;
    memset(arr, 0, sizeof(arr));

    cin >> N;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        cin >> arr[i][j];
      }
    }

    vector <pair <int, int>> v; // 최대값, 방 번호
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        dfs(i, j, 1);
        v.push_back({res, arr[i][j]});
        res = 0;
      }
    }
    sort(v.begin(), v.end(), cmp);

    cout << "#" << TC << " " << v[0].second << " " << v[0].first << "\n";
    TC++;
  }

  return 0;
}
