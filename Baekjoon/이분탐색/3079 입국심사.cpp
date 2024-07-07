#include <algorithm>
#include <iostream>

using namespace std;

int M, N;       // 상근이와 친구들, 입국심사대
long long Tk[100001]; // 각 심사대에서 심사를 하는데 걸리는 시간
long long maxTime = 0;

long long binary_search() {
    long long start = 1;
    long long end = M * maxTime; // M * Tk
    long long res = M * maxTime;

    while (start <= end) {
        long long sum = 0; // 심사할 수 있는 친구들 수
        long long mid = (start + end) / 2;

        for (int i = 0; i < N; i++) {
            sum += (mid / Tk[i]);
            if (sum > M) break; // 없으면 오버플로우 발생
        }

        if (sum >= M) {
            end = mid - 1;
            res = min(res, mid);
        }
        else {
            start = mid + 1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> Tk[i];
        maxTime = max(maxTime, Tk[i]);
    }
    cout << binary_search();
}