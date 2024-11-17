#include <bits/stdc++.h>
using namespace std;

/*
  규영이가 받은 카드의 수
  1 ~ 18중에 9장
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    int arr[10]; // 규영
    vector <int> v; // 인영
    int cnt = 0, cnt1 = 0;

    // 규영 내기
    for(int i = 0; i < 9; i++){
      cin >> arr[i];
    }
    // 인영 내기 (자동 정렬)
    for(int i = 1; i <= 18; i++){
      if (find(arr, arr + 9, i) == arr + 9) {
        v.push_back(i);
      }
    }

    do {
      // 규영 인영 대결
      int sum = 0, sum1 = 0;
      for(int i = 0; i < 9; i++) {
        if (arr[i] > v[i]) sum += arr[i] + v[i];
        else sum1 += arr[i] + v[i];
      }
      if (sum > sum1) cnt++;
      else cnt1++;
    } while(next_permutation(v.begin(), v.end()));

    cout << "#" << TC << " " << cnt << " " << cnt1 << "\n";
    TC++;

  }
}