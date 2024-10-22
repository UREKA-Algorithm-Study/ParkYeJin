#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int apple[101][101];
bool snake[101][101];
int dir; // 0 동, 1 남, 2, 서, 3 북

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector <pair <int, char>> v; // 초, 방향

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  cin >> K; // 사과의 개수
  for(int i = 0; i < K; i++){
    int R, C;
    cin >> R >> C;
    apple[R][C] = 1; // 사과의 위치
  }
  cin >> L;
  for(int i = 0; i < L; i++){
    int X;
    char C;
    cin >> X >> C;
    v.push_back({X, C});
  }

  deque<pair<int, int>> snake_pos; // 뱀의 머리와 꼬리 위치
  snake_pos.push_back({1, 1}); // 뱀의 초기 위치
  snake[1][1] = true; // 뱀 초기 위치

  int sec = 0, idx = 0;

  while(1) {
    sec++;

    // 1. 머리 이동
    int hx = snake_pos.front().first;
    int hy = snake_pos.front().second;
    int nx = hx + dx[dir];
    int ny = hy + dy[dir];

    // 벽 또는 자기 자신과 충돌하면 종료
    if (nx < 1 || nx > N || ny < 1 || ny > N || snake[nx][ny]) break;

    snake_pos.push_front({nx, ny});
    snake[nx][ny] = true;

    // 2. 사과 유무
    if (!apple[nx][ny]) {
      int tx = snake_pos.back().first;
      int ty = snake_pos.back().second;
      snake[tx][ty] = false;
      snake_pos.pop_back();
    } else {
      apple[nx][ny] = 0;
    }

    // 3. 회전 처리
    if (idx < L && sec == v[idx].first) {
      if (v[idx].second == 'D') {
        dir = (dir + 1) % 4; // 오른쪽 회전
      } else {
        dir = (dir + 3) % 4; // 왼쪽 회전
      }
      idx++; 
    }
  }
  cout << sec;
  return 0;
} 