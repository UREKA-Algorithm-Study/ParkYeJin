#include <algorithm>
#include <iostream>
using namespace std;

struct Point {
  double x, y;
};

double res;
Point p[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }

  for (int i = 1; i < N - 1; i++) {
    res += ((p[i].y - p[0].y) * (p[i + 1].x - p[0].x) -
            (p[i].x - p[0].x) * (p[i + 1].y - p[0].y)) /
           2;
  }
  cout.precision(1);
  cout << fixed;
  cout << abs(res);

  return 0;
}