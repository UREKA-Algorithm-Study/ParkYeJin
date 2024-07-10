#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, A[2001];

bool binary_search(int idx) {
  int left = 0;
  int right = N - 1;

  while (left < right) {
    int sum = A[left] + A[right];

    if (sum == A[idx]){
      // 본인일 경우 무시
      if (left == idx) left++;
      else if (right == idx) right--;
      else return true;
    }
    else {
      if (sum > A[idx]) right--;
      else left++;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  int res = 0;
  for (int i = 0; i < N; i++) {
    if (binary_search(i))
      res++;
  }
  cout << res;
}