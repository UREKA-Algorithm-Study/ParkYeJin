#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>> q;

void combine() {
  long long first = q.top();
  q.pop();
  long long second = q.top();
  q.pop();

  q.push(first + second);
  q.push(first + second);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int card;
    cin >> card;
    q.push(card);
  }
  for (int i = 0; i < m; i++) {
    combine();
  }

  long long res = 0;
  while (!q.empty()) {
    long long top = q.top();
    q.pop();
    res += top;
  }

  cout << res;

  return 0;
}