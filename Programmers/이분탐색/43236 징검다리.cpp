#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int binary_search(int distance, vector<int> rocks, int n, int &answer) {
    int left = 1;
    int right = distance;

    while (left <= right) {
        int mid = (left + right) / 2;
        int prev = 0, remove = 0;

        // 바위 거리 체크
        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - prev < mid) remove++; // 돌 제거
            else prev = rocks[i];
        }
        if (distance - prev < mid) remove++;  
        
        // 바위 사이 거리의 최솟값을 mid로 할 수 있을 경우
        if (remove <= n) { 
            answer = max(mid, answer);
            left = mid + 1;
        } else right = mid - 1;
    }
    return answer;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    answer = binary_search(distance, rocks, n, answer);

    return answer;
}