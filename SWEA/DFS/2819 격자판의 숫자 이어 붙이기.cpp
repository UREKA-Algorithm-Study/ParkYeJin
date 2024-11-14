#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int arr[5][5];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

set <int> s;

void dfs(int x, int y, string str, int cnt){
  if (cnt == 7) {
    s.insert(stoi(str));
    return;
  }

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
    char num = arr[nx][ny] + '0';
    dfs(nx, ny, str + num, cnt + 1); // 숫자 -> 문자
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    s.clear();
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        cin >> arr[i][j];
      }
    }
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        dfs(i, j, "", 0);
      }
    }
    
    cout << "#" << TC << " " << s.size() << "\n";
    TC++;
  }

  return 0;
}
