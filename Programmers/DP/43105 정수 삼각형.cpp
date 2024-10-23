#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j < i + 1; j++){
            // 왼쪽 줄
            if (j == 0) dp[i][j] = dp[i-1][j];
            // 제일 오른쪽 줄
            else if (j == i) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
            
            dp[i][j] += triangle[i][j];
        }
    }
    
    // 마지막 줄 가장 큰 값
    for(int i = 0; i < triangle.size(); i++){
        answer = max(answer, dp[triangle.size() - 1][i]);
    }
    
    return answer;
}