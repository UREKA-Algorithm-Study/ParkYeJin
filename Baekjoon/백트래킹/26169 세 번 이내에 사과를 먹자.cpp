#include <iostream>
#include <algorithm>

using namespace std;

int r, c;
int arr[5][5];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool result;
bool visited[5][5]; 

// 사과 1, 장애물 -1

void dfs(int cx, int cy, int depth, int ocnt){
  visited[cx][cy] = true;
  
  if (depth == 3) {
    if (ocnt >= 2) {
      result = true;
    }
    return;
  }

  for(int i = 0; i < 4; i++){
    int nx = cx + dx[i];
    int ny = cy + dy[i];

    if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
    if (!visited[nx][ny] && arr[nx][ny] != -1) {
      dfs(nx, ny, depth + 1, arr[nx][ny] == 1 ? ocnt + 1 : ocnt);
      visited[nx][ny] = false;
    }
  }
}

int main(){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> arr[i][j];
    }
  }
  cin >> r >> c;
  dfs(r, c, 0, 0);
  cout << result;
  
  return 0;
}