const input = require("fs").readFileSync("./input.txt").toString().split("\n");

/*
  물품의 수 N, 버틸 수 있는 무게 K
  각 물건의 무게 W, 해당 물건의 가치 V
*/

const [N, K] = input[0].split(" ").map(Number);
const W = Array(N + 1).fill(0);
const V = Array(N + 1).fill(0);
const dp = Array.from(Array(N + 1), () => Array(K + 1).fill(0));

for (let i = 0; i < N; i++) {
  const [weight, value] = input[i + 1].split(" ").map(Number);
  W[i + 1] = weight;
  V[i + 1] = value;
}

for (let i = 1; i <= N; i++) {
  for (let j = 1; j <= K; j++) {
    // 담을 수 있는 경우
    if (j >= W[i]) {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
    }
    // 담을 수 없는 경우
    else dp[i][j] = dp[i - 1][j];
  }
}
//console.log(dp);

console.log(dp[N][K]);
