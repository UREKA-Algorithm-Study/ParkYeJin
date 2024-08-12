#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int w, h, store, d, x;
int dir[101], y[101];

int game(int dir, int y) {
  // 방향 같은 경우
  if (d == dir) {
    if (x > y)
      return x - y;
    else
      return y - x;
  }
  // 방향 다른 경우
  else {
    if (d == 1) { // 북쪽
      switch (dir) {
      case 2:
        return min(x + h + y, (w - x) + h + (w - y));
      case 3:
        return x + y;
      case 4:
        return (w - x) + y;
      }
    } else if (d == 2) { // 남쪽
      switch (dir) {
      case 1:
         return min(x + h + y, (w - x) + h + (w - y));
      case 3:
        return x + (h - y);
      case 4:
        return (w - x) + (h - y);
      }
    } else if (d == 3) { // 서쪽
      switch (dir) {
      case 1:
        return x + y;
      case 2:
        return (h - x) + y;
      case 4:
        return min(x + w + y, (h - x) + w + (h - y));
      }
    } else if (d == 4) { // 동쪽
      switch (dir) {
      case 1:
        return x + (w - y);
      case 2:
        return (h - x) + (w - y);
      case 3:
        return min(x + w + y, (h - x) + w + (h - y));
      }
    }
  }
  return 0;
}

int main() {
  cin >> w >> h >> store;
  for (int i = 0; i < store; i++) {
    cin >> dir[i] >> y[i];
  }
  cin >> d >> x;

  int sum = 0;
  for (int i = 0; i < store; i++) {
    sum += game(dir[i], y[i]);
  }
  cout << sum;

  return 0;
}