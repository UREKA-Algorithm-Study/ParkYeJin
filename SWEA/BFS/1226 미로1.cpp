#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
  1 벽, 0 길, 2 출발점, 3 도착점
*/

char arr[16][16];
bool visited[16][16];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

void bfs(int x, int y){
  queue <pair <int, int>> q;
  q.push({x, y});

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    visited[x][y] = true;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx > 15 || ny < 0 || ny > 15) continue;
      if (!visited[nx][ny] && arr[nx][ny] != '1') {
        q.push({nx, ny});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T = 10;
  while(T--){
    int TC;
    cin >> TC;
    int sx, sy, ex, ey;
    for(int i = 0; i < 16; i++){
      for(int j = 0; j < 16; j++){
        cin >> arr[i][j];
        if (arr[i][j] == '2') sx = i, sy = j;
        else if (arr[i][j] == '3') ex = i, ey = j;
      }
    }
    bfs(sx, sy);

    int res = visited[ex][ey] ? 1 : 0;
    cout << "#" << TC << " " << res << "\n";

    memset(visited, 0, sizeof(visited));
  }

  return 0;
}
