#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

/*
  가로 -> 세로 -> 9칸
  처음 0의 개수 세어, cnt 다 되면 탈출
*/

int sudoku[10][10];
int zeroCnt = 0;
vector <pair <int, int>> v; // 0 idx

// 값을 넣을 수 있는지 확인
bool check(int x, int y, int num){
  // 가로, 세로 확인
  for(int i = 1; i <= 9; i++){
    if (num == sudoku[x][i]) return false;
    if (num == sudoku[i][y]) return false;
  }
  // 정사각형 확인
  int sx = (x - 1) / 3 * 3 + 1;
  int sy = (y - 1) / 3 * 3 + 1;
  for(int i = sx; i < sx + 3; i++){
    for(int j = sy; j < sy + 3; j++){
      if (sudoku[i][j] == num) return false;
    }
  }
  return true;
}

bool flag = false;

void dfs(int depth) {
  if (flag) return;
  if (depth == zeroCnt) {
    for(int i = 1; i <= 9; i++){
      for(int j = 1; j <= 9; j++){
        cout << sudoku[i][j] << " ";
      }
      cout << "\n";
    }
    flag = true;
    return;
  }

  // 0인 idx
  int x = v[depth].first;
  int y = v[depth].second;

  for(int n = 1; n <= 9; n++){
    if (check(x, y, n)) {
      sudoku[x][y] = n;
      dfs(depth + 1);
      sudoku[x][y] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= 9; j++){
      cin >> sudoku[i][j];
      if (sudoku[i][j] == 0) {
        v.push_back({i, j});
        zeroCnt++;
      }
    }
  }
  dfs(0);

  return 0;
}