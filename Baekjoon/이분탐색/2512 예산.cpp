#include <algorithm>
#include <iostream>
using namespace std;

int N, M, res;         // 지방의 수, 총 예산
int money[10001]; // 지방의 예산요청
int maxM; // 예산요청 중 가장 큰 값

int binary_search() {
  int left = 1;
  int right = maxM;

  while(left <= right) {
    int mid = (left + right) / 2;

    int sum = 0;
    for(int i = 0; i < N; i++){
      if (money[i] < mid) sum += money[i];
      else sum += mid;
    }
    if (sum <= M) {
      left = mid + 1;
      res = max(res, mid);
    } else {
      right = mid - 1;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> money[i];
    maxM = max(maxM, money[i]);
  }
  cin >> M;
  cout << binary_search();
}