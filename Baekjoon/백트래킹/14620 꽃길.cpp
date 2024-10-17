#include <bits/stdc++.h>
using namespace std;

int N, res = 1e9;
int price[11][11];
bool visited[11][11];

const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, -1, 0, 1};

void dfs(int depth){
  if(depth == 3) {
    int sum = 0;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if (visited[i][j]) {
          sum += price[i][j];
        }
      }
    }
    res = min(res, sum);
    return;
  }

  for(int i = 2; i < N; i++){
    for(int j = 2; j < N; j++){
      int cnt = 0;
      for(int k = 0; k < 5; k++){
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (!visited[nx][ny]) cnt++;
      }
      if (cnt == 5) {
        for(int k = 0; k < 5; k++){
          int nx = i + dx[k];
          int ny = j + dy[k];
          visited[nx][ny] = true;
        }
        dfs(depth + 1);
        for(int k = 0; k < 5; k++){
          int nx = i + dx[k];
          int ny = j + dy[k];
          visited[nx][ny] = false;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> price[i][j];
    }
  }
  dfs(0);
  cout << res;

  return 0;
} 