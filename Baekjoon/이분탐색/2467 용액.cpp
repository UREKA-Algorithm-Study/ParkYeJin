#include <algorithm>
#include <iostream>

using namespace std;

int N;
int num[100001];
int sum = 2000000001;

int res1, res2;
void binary_search() {
  int left = 0;
  int right = N - 1;

  while (left < right) {
    int plus = abs(num[left] + num[right]);
    if (plus < sum) {
      sum = plus;
      res1 = num[left];
      res2 = num[right];
    }
    if (num[left] + num[right] < 0)
      left++;
    else
      right--;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
  }

  binary_search();
  cout << res1 << " " << res2;
}