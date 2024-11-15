#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

char arr[101][101];

bool painCheck(string str){
  string ostr = str;
  reverse(str.begin(), str.end());

  if (ostr == str) return true;
  else return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC;
  cin >> T;
  while(T--){
    cin >> TC;
    for(int i = 0; i < 100; i++){
      for(int j = 0; j < 100; j++){
        cin >> arr[i][j];
      }
    }

    int maxRes = 0;
    // 모든 길이에 대한 부분 문자열 확인
    for (int len = 1; len <= 100; len++) {
      for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= 100 - len; j++) {
          // 행에 대한 회문 체크
          string rstr = "";
          for (int k = 0; k < len; k++) {
            rstr += arr[i][j + k]; // 길이 len 부분 문자열 추출
          }
          if (painCheck(rstr)) {
            maxRes = max(maxRes, len);
          }

          // 열에 대한 회문 체크
          string cstr = "";
          for (int k = 0; k < len; k++) {
            cstr += arr[j + k][i]; // 길이 len 부분 문자열 추출
          }
          if (painCheck(cstr)) {
            maxRes = max(maxRes, len);
          }
        }
      }
    }

    cout << "#" << TC << " " << maxRes << "\n";
  }

  return 0;
}
