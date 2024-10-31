const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

const sudoku = Array.from(Array(10), () => Array(10).fill(0));

let zeroCnt = 0;
let zeroIdx = [];

// 스도쿠 입력받기
for (let i = 1; i <= 9; i++) {
  const row = input[i - 1].split(" ").map(Number);
  for (let j = 1; j <= 9; j++) {
    sudoku[i][j] = row[j - 1];
    if (sudoku[i][j] === 0) {
      zeroCnt++;
      zeroIdx.push([i, j]);
    }
  }
}

// 값이 들어갈 수 있는지 확인
function check(x, y, n) {
  // 가로, 세로 확인
  for (let i = 1; i <= 9; i++) {
    if (sudoku[x][i] === n) return false;
    if (sudoku[i][y] === n) return false;
  }
  // 정사각형 확인
  let sx = Math.floor((x - 1) / 3) * 3 + 1;
  let sy = Math.floor((y - 1) / 3) * 3 + 1;
  for (let i = sx; i < sx + 3; i++) {
    for (let j = sy; j < sy + 3; j++) {
      if (sudoku[i][j] === n) return false;
    }
  }
  return true;
}

let flag = false;

// 모든 경우의 수
function dfs(depth) {
  if (flag) return;
  // 0이 다 채워졌다면
  if (depth === zeroCnt) {
    for (let i = 1; i <= 9; i++) {
      let line = "";
      for (let j = 1; j <= 9; j++) {
        line += sudoku[i][j] + " ";
      }
      console.log(line);
    }
    flag = true;
    return;
  }

  let x = zeroIdx[depth][0];
  let y = zeroIdx[depth][1];

  for (let n = 1; n <= 9; n++) {
    if (check(x, y, n)) {
      sudoku[x][y] = n;
      dfs(depth + 1);
      sudoku[x][y] = 0;
    }
  }
}

dfs(0);
