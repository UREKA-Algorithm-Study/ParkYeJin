#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, Rcnt, Gcnt, Bcnt, RGcnt;
string str[101];
bool visited[101][101];
bool noColor; // 적록색약

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

queue <pair <int, int>> q;

void bfs(int x, int y, char color){
  q.push({x, y});
  visited[x][y] = 1;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) continue;
      // 적록색약 x
      if (!noColor && str[nx][ny] == color && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = 1;
      }
      // 적록색약 o
      if (noColor && (str[nx][ny] == color || str[nx][ny] == 'G' ) && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // 적록색약 x R, G, B
  // 적록색약 o RG, B
  
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> str[i];
  }

  // 적록색약 x
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if (!visited[i][j]) {
        if (str[i][j] == 'R') {
          bfs(i, j, 'R');
          Rcnt++;
        }
        else if (str[i][j] == 'G') {
          bfs(i, j, 'G');
          Gcnt++;
        }
        else if (str[i][j] == 'B') {
          bfs(i, j, 'B');
          Bcnt++;
        }
      }
    }
  }

  memset(visited, 0, sizeof(visited));
 
  noColor = true; // 적록색약 o
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if (!visited[i][j]) {
        if (str[i][j] == 'R' || str[i][j] == 'G') {
          bfs(i, j, 'R');
          RGcnt++;
        }
      }
    }
  }
  
  cout << Rcnt + Gcnt + Bcnt << " " << RGcnt + Bcnt;
  
}