#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

char arr[50][50];
int num[50][50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC=1;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
        num[i][j] = arr[i][j] - '0'; 
      }
    }

    int sum = 0;

    int cnt = 0;
    for(int i = 0; i < n / 2 + 1; i++){
      for(int j = 0; j < i * 2 + 1; j++){ // 횟수
        sum += num[i][j + n / 2 - cnt]; // 시작점
      }
      cnt++;
    }

    int cnt1 = 1;
    for(int i = n / 2 + 1; i < n; i++){
      for(int j = 0 ; j < (n - i) * 2 - 1; j++){ // 횟수
        sum += num[i][j + cnt1]; // 시작점
      }
      cnt1++;
    }

    cout << "#" << TC << " " << sum << "\n";
    TC++;
  }

  return 0;
}
