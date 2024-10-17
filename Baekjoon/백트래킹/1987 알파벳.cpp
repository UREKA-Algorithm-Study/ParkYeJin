#include <bits/stdc++.h>
using namespace std;

int R, C, res;
char arr[21][21];
bool visited[21][21];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

bool alpha[26];

void dfs(int x, int y, int cnt){
  res = max(res, cnt);

  visited[x][y] = true;
  alpha[arr[x][y] - 'A'] = true; 

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
    if (!visited[nx][ny] && !alpha[arr[nx][ny] - 'A']) {
      dfs(nx, ny, cnt + 1);
    }
  }

  visited[x][y] = false;
  alpha[arr[x][y] - 'A'] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> R >> C;
  for(int i = 1; i <= R; i++){
    for(int j = 1; j <= C; j++){
      cin >> arr[i][j];
    }
  }

  dfs(1, 1, 1);
  cout << res;

  return 0;
} 



// set사용 O(logN) 시간초과
#include <bits/stdc++.h>
using namespace std;

int R, C, res;
char arr[21][21];
bool visited[21][21];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

set<char> alpha; // 중복x

void dfs(int x, int y, int cnt){
  res = max(res, cnt); // 최대 칸수 갱신
  
  visited[x][y] = true;
  alpha.insert(arr[x][y]); 

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
    if (!visited[nx][ny] && alpha.find(arr[nx][ny]) == alpha.end()) {
      dfs(nx, ny, cnt + 1);
    }
  }

  visited[x][y] = false;
  alpha.erase(arr[x][y]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> R >> C;
  for(int i = 1; i <= R; i++){
    for(int j = 1; j <= C; j++){
      cin >> arr[i][j];
    }
  }

  dfs(1, 1, 1);
  cout << res;

  return 0;
} 