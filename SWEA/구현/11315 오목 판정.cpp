#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
char arr[21][21];
bool flag;

const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve(int x, int y) {
  for(int i = 0; i < 8; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) continue;
    int cnt = 1;
    while(0 <= nx && nx <= N - 1 && 0 <= ny && ny <= N - 1 && arr[nx][ny] == 'o') {
      nx += dx[i];
      ny += dy[i];
      cnt++;
      if (cnt == 5) {
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> N;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cin >> arr[i][j];
      }
    }

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if (arr[i][j] == 'o') solve(i, j);
      }
    }

    string res = flag ? "YES" : "NO";
    cout << "#" << TC << " " << res << " " << "\n";
    TC++;

    flag = false;
  }

  return 0;
}
