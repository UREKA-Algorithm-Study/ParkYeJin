#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, R, C, descent;
int height[101];
char arr[101][101];
bool cVisited[101][101];
bool visited[101][101];

queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

// 땅에 붙은 클러스터 방문하는 함수
void bfs(int x, int y) {
  q.push({x, y});
  visited[x][y] = 1;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > R || ny < 1 || ny > C)
        continue;
      if (!visited[nx][ny] && arr[nx][ny] == 'x') {
        q.push({nx, ny});
        visited[nx][ny] = 1;
      }
    }
  }
}

// 미네랄 파괴하는 함수
void destory(int idx) {
  if (idx % 2 == 0) { // 왼 -> 오
    for (int i = 1; i <= C; i++) {
      char c = arr[R - height[idx] + 1][i];
      if (c == 'x') {
        arr[R - height[idx] + 1][i] = '.';
        break;
      }
    }
  } else { // 오 -> 왼
    for (int i = C; i >= 0; i--) {
      char c = arr[R - height[idx] + 1][i];
      if (c == 'x') {
        arr[R - height[idx] + 1][i] = '.';
        break;
      }
    }
  }
}

// 공중 클러스터 찾는 함수
bool airCluster() {
  // 바닥에 닿은 클러스터 방문
  for (int j = 1; j <= C; j++) {
    if (arr[R][j] == 'x' && !visited[R][j]) {
      bfs(R, j);
    }
  }
  // 공중 클러스터 체크
  bool flag = false;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (arr[i][j] == 'x' && !visited[i][j]) {
        cVisited[i][j] = 1;
        flag = true;
      }
    }
  }
  return flag;
}

// 공중 클러스터 얼만큼 떨어트리는지 계산 함수
void descentCal() {
  for (int j = 1; j <= C; j++) {
    int bottom = 0;  // 공중 클러스터 맨밑
    bool flag = false;
    for (int i = 1; i <= R; i++) {
      if (cVisited[i][j]) {
        bottom = i;
        flag = true;
      }
      // 공중 클러스터 이후에 클러스터 나오면 나감
      if (flag && arr[i][j] == 'x' && visited[i][j]) break;
    }
    int top = R + 1; // 땅 클러스터 맨위
    for(int i = top; i >= bottom + 1; i--){
      if (arr[i][j] == 'x' && visited[i][j]) {
        top = i;
      }
    }   
    if (flag) { // 공중 클러스터 있을 경우에만 최소값 업데이트
       descent = min(descent, top - bottom - 1);
    }
  }
}

// descent만큼 클러스터 떨어트리는 함수
void descentCluster() {
  for (int i = R; i >= 1; i--) {
    for (int j = 1; j <= C; j++) {
      if (cVisited[i][j]) {
        arr[i][j] = '.';
        arr[i + descent][j] = 'x';
      }
    }
  }
}

// 땅, 공중 클러스터 초기화하는 함수
void init() {
  memset(cVisited, 0, sizeof(cVisited));
  memset(visited, 0, sizeof(visited));
  descent = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> R >> C;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> arr[i][j];
    }
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> height[i];
  }
  for (int k = 0; k < N; k++) {
    destory(k);              // 미네랄 파괴
    bool air = airCluster(); // 공중 클러스터 표시
    descent = R;
    if (air) {
      descentCal();     // 얼만큼 떨어트리는지 계산
      descentCluster(); // 공중에서 떨어트리기
    }
    init(); // 땅, 공중 클러스터 초기화
  }

  // 최종 결과
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cout << arr[i][j];
    }
    cout << "\n";
  }
}