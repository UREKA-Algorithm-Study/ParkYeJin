#include <bits/stdc++.h>
using namespace std;

int N, scv[3];
int dp[64][64][64];
int visited[64][64][64];
int arr[6][3] = {
  {9, 3, 1},
  {9, 1, 3},
  {3, 1, 9}, 
  {3, 9, 1}, 
  {1, 3, 9}, 
  {1, 9, 3}
};
struct A {
  int a, b, c;
};

queue <A> q;

int solve(int a, int b, int c){
  visited[a][b][c] = 1;
  q.push({a, b, c});

  while(!q.empty()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();

    if (visited[0][0][0]) break;
    for(int i = 0; i < 6; i++){
      int na = max(0, a - arr[i][0]);
      int nb = max(0, b - arr[i][1]);
      int nc = max(0, c - arr[i][2]);
      if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = visited[a][b][c] + 1;
        q.push({na, nb, nc});
      }
    }
  }
  return visited[0][0][0] - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> scv[i];
  }
  cout << solve(scv[0], scv[1], scv[2]);

  return 0;
} 