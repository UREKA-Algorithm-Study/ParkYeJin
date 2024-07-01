#include <iostream>
#include <cmath>

using namespace std;

long long arr[100001];
long long *min_tree;
long long *max_tree;

// start end 현재 노드가 포함하는 구간의 범위
void init(int node, int start, int end) {
  // 리프노드 o
  if (start == end) { 
    min_tree[node] = max_tree[node] = arr[start];
    return;
  }
  // 리프노드 x
  int mid = (start + end) / 2;
  init(node * 2, start, mid);
  init(node * 2 + 1, mid + 1, end);
  min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
  max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
  return;
}

pair <int, int> findRes(int node, int start, int end, int left, int right){
  if (left > end || right < start) return {INT32_MAX, 0};
  if (left <= start && end <= right) return {min_tree[node], max_tree[node]};

  pair<int, int> l, r;
  int mid = (start + end) / 2;
  l = findRes(node * 2, start, mid, left, right);
  r = findRes(node * 2 + 1, mid + 1, end, left, right);
  return {min(l.first, r.first), max(l.second, r.second)};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  int height = ceil(log2(N));
  min_tree = new long long[1 << (height + 1)];
  max_tree = new long long[1 << (height + 1)];
  
  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }
  init(1, 1, N); // 세그먼트 트리 초기화
  
  for(int j = 0; j < M; j++){
    int a, b;
    cin >> a >> b;
    // node, start, end, left, right
    pair <int, int> result;
    result = findRes(1, 1, N, a, b);
    cout << result.first << " " << result.second << "\n";
  }
  
  return 0;
}