#include <iostream>
#include <cmath>
#define MAX 1000000001

using namespace std;

long long arr[100001];
long long *min_tree;

long long init(int node, int start, int end) {
  // 리프노드 o
  if (start == end) return min_tree[node] = arr[start];
  // 리프노드 x
  int mid = (start + end) / 2;
  return min_tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

long long findMin(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return MAX;
  if (left <= start && end <= right) return min_tree[node];

  int mid = (start + end) / 2;
  return min(findMin(node * 2, start, mid, left, right), findMin(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  int height = ceil(log2(N));
  min_tree = new long long[1 << (height + 1)];

  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }
  init(1, 1, N); // 세그먼트 트리 초기화
  
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    cout << findMin(1, 1, N, a, b) << "\n";
  }
  
  return 0;
}