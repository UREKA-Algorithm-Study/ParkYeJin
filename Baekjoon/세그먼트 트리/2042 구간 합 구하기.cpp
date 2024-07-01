#include <iostream>
#include <cmath>

using namespace std;

long long arr[1000001];
long long *tree;

/* 
  리프노드 o - 배열의 수
  리프노드 x - 왼쪽노드 + 오른쪽 노드
  왼쪽 자식 [start, (start + end) / 2]
  오른쪽 자식 [(start + end) / 2 + 1, end]
*/

long long init(int node, int start, int end){
  // 리프노드 o
  if (start == end) return tree[node] = arr[start];
  // 리프노드 x
  int mid = (start + end) / 2;
  return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end); 
}

/* 
  1. [left, right]와 [start, end]가 겹치지 않는 경우
  2. [left, right]가 [start, end]를 완전히 포함하는 경우
  3. [start, end]가 [left, right]를 완전히 포함하는 경우
  4. [left, right]와 [start, end]가 겹쳐져 있는 경우(1,2,3 제외한 나머지 경우)
*/

long long sum(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

/*
  index번째 수 a[index]
  바뀐 수 val
  합 val - a[index]

  1. [start, end]에 index 포함되는 경우 - 재귀호출 진행
  2. [start, end]에 index 포함되지 않는 경우 - 재귀호출 중단
*/

void update(int node, int start, int end, int idx, long long diff) {
  if (idx < start || idx > end) return;
  tree[node] += diff;
  if (start == end) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, diff);
  update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // a가 1인 경우 b -> c
  // a가 2인 경우 b번째 수부터 c번째 수까지의 합
    
  int N, M, K; 
  cin >> N >> M >> K;
  
  int height = ceil(log2(N));
  tree = new long long[1<<(height+1)];
  
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  init(1, 0, N - 1); // node, start, end

  for(int i = 0; i < M + K; i++){
    int a;
    long long b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      long long diff = c - arr[b - 1];
      arr[b - 1] = c;
      // node, start, end, idx, diff 
      update(1, 0, N - 1, b - 1, diff);
    }
    else if (a == 2) {
      // node, start, end, left, right
      cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
    }
  }
  return 0;
}