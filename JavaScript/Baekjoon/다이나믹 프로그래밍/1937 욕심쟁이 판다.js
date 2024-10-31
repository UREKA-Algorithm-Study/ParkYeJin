const input = require("fs").readFileSync("./input.txt").toString().split("\n");

const n = Number(input[0]);
const arr = Array.from(Array(n + 1), () => Array(n + 1).fill(0));
const dp = Array.from(Array(n + 1), () => Array(n + 1).fill(0));

for (let i = 1; i <= n; i++) {
  const row = input[i].split(" ").map(Number);
  for (let j = 1; j <= n; j++) {
    arr[i][j] = row[j - 1];
  }
}

const dx = [1, 0, -1, 0];
const dy = [0, -1, 0, 1];

function dfs(x, y) {
  if (dp[x][y]) return dp[x][y];
  dp[x][y] = 1;

  for (let i = 0; i < 4; i++) {
    let nx = x + dx[i];
    let ny = y + dy[i];

    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
    if (arr[nx][ny] > arr[x][y]) {
      dp[x][y] = Math.max(dp[x][y], dfs(nx, ny) + 1);
    }
  }
  return dp[x][y];
}

let res = 0;
for (let i = 1; i <= n; i++) {
  for (let j = 1; j <= n; j++) {
    res = Math.max(res, dfs(i, j));
  }
}

for (let i = 1; i <= n; i++) {
  let line = "";
  for (let j = 1; j <= n; j++) {
    line += dp[i][j] + " ";
  }
  console.log(line);
}

//console.log(res);
