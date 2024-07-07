#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;       // 자연수 N
int U[1001]; // U의 원소

vector<int> sum;

// num 값이 sum 벡터에 존재하는지
bool binary_search(int num) {
  int start = 0;
  int end = sum.size() - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (sum[mid] == num)
      return true;
    if (sum[mid] < num) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  /* k번째 수가 최대가 되도록 하는 것이 목적이다.
  x, y, z, k가 서로 같아도 된다 */

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> U[i];
  }
  // 가능한 두 수의 합
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      sum.push_back(U[i] + U[j]);
    }
  }
  sort(U, U + N);
  sort(sum.begin(), sum.end());

  for (int i = N - 1; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      int num = U[i] - U[j];
      if (binary_search(num)) {
        cout << U[i] << endl;
        return 0;
      }
    }
  }
}