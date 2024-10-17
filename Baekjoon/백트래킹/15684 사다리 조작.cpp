#include <bits/stdc++.h>
using namespace std;
int res = 4;
int N, M, H;
bool visited[31][11];

// i줄이 i번째에 도착하는지
bool check(){
  for(int i = 1; i <= N; i++){
    int start = i;
    for(int j = 1; j <= H; j++){
      if (visited[j][start]) start++;
      else if (visited[j][start - 1]) start--;
    }
    if (start != i) return false;
  }
  return true;
}

void go(int now, int cnt) {
  if (cnt > 3) return;
  if (check()) {
    res = min(res, cnt);
    return;
  }

  for(int i = now; i <= H; i++){
    for(int j = 1; j <= N; j++){
      if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
      visited[i][j] = true;
      go(i, cnt + 1);
      visited[i][j] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M >> H;
  for(int i = 0; i < M; i++){
    int a, b; // a 점선 위치, b 세로선, b + 1 세로선 연결
    cin >> a >> b;
    visited[a][b] = true;
  }
  go(1, 0);

  if (res == 4) cout << -1;
  else cout << res;

  return 0;
} 