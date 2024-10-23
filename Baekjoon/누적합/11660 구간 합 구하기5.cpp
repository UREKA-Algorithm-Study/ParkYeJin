#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

/*
  2차원 누적합
  표의 크기 N, 합을 구해야하는 횟수 M
*/

int N, M;
int arr[1025][1025];
int prefixSum[1025][1025];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    for(int j= 1; j <= N; j++){
      cin >> arr[i][j];
      prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + arr[i][j];
    }
  }

  while(M--){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1] << "\n";
  }

  return 0;
}
