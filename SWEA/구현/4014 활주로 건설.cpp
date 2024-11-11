#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  int T, TC = 1;
  cin >> T;
  while(T--){
    int arr[21][21];
    int N, X; // 크기, 경사로 길이
    cin >> N >> X;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        cin >> arr[i][j];
      }
    }

    int res = 0;
    for(int i = 1; i <= N; i++){
      // 행 검사
      int cnt = 1; // 높이가 같은 타일 수
      for(int j = 2; j <= N; j++){
        int prev = arr[i][j - 1];
        int cur = arr[i][j];

        if (prev == cur) cnt++;
        // 내리막
        else if (prev - cur == 1 && cnt >= 0) {
          cnt = -X + 1;
        } 
        // 오르막
        else if (prev - cur == -1 && cnt >= X) {
          cnt = 1;
        } 
        // 높이차 1보다 클 경우 불가능
        else {
          cnt = -1;
          break;
        }
      }
      if (cnt >= 0) res++;


      // 열 검사
      cnt = 1;
      for(int j = 2; j <= N; j++){
        int prev = arr[j - 1][i];
        int cur = arr[j][i];
        if (prev == cur) cnt++;
        // 내리막
        else if (prev - cur == 1 && cnt >= 0) {
          cnt = -X + 1;
        }
        // 오르막
        else if (prev - cur == -1 && cnt >= X) {
          cnt = 1;
        }
        // 높이차 1보다 클 경우 불가능
        else {
          cnt = -1;
          break;
        }
      }
      if (cnt >= 0) res++;
    }

    cout << "#" << TC << " " << res << "\n";
    TC++;
  }

  return 0;
}