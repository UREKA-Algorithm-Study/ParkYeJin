const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

/*
    H행 W열
    동 >, 서 <, 남 v, 북 ^ 
    L 왼쪽 90도 회전 
    R 오른쪽 90도 회전 
    A 두칸 전진

    같은 칸 방문 x
    사수 방문 #, 방문 안 하면 .
    사수가 표시한 모든 칸들만 방문하도록 로봇 조작

    1. 어떤 칸, 어떤 방향
    2. 어떤 명령어 순서대로 입력
*/

const [H, W] = input[0].split(" ").map(Number);
const arr = Array.from(Array(H + 1), () => Array(W + 1).fill(0));
const visited = Array.from(Array(H + 1), () => Array(W + 1).fill(0));

// 입력
for (let i = 1; i <= H; i++) {
  const row = input[i];
  for (let j = 1; j <= W; j++) {
    arr[i][j] = row[j - 1];
  }
}

const dx = [0, 1, 0, -1];
const dy = [1, 0, -1, 0];

// 동남서북
const dx2 = [0, 2, 0, -2];
const dy2 = [2, 0, -2, 0];

// #인 곳 동서남북 #계산
let sx,
  sy,
  sdir = -1; // 시작 방향
let minCnt = 5;
for (let i = 1; i <= H; i++) {
  for (let j = 1; j <= W; j++) {
    if (arr[i][j] === "#") {
      let cnt = 0,
        d = -1;
      for (let k = 0; k < 4; k++) {
        let nx = i + dx[k];
        let ny = j + dy[k];

        if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
        if (arr[nx][ny] === "#") {
          cnt++;
          d = k;
        }
      }
      // 시작위치
      if (minCnt > cnt) {
        minCnt = cnt;
        sx = i;
        sy = j;
        sdir = d;
      }
    }
  }
}

let res = ""; // 명령어
const queue = [];
queue.push([sx, sy]);
visited[sx][sy] = true;

let ctl = sdir; // 이전의 방향

while (queue.length > 0) {
  let [x, y] = queue.shift();
  //console.log(x, y, "방향", ctl);

  for (let i = 0; i < 4; i++) {
    let nx1 = x + dx[i];
    let ny1 = y + dy[i];

    let nx2 = x + dx2[i];
    let ny2 = y + dy2[i];

    if (nx1 < 1 || nx1 > H || ny1 < 1 || ny1 > W) continue;
    if (nx2 < 1 || nx2 > H || ny2 < 1 || ny2 > W) continue;
    if (
      arr[nx1][ny1] === "#" &&
      !visited[nx1][ny1] &&
      arr[nx2][ny2] === "#" &&
      !visited[nx2][ny2]
    ) {
      if (ctl !== i) {
        if (i - ctl === 1 || i - ctl === -3) res += "R";
        else if (ctl - i === 1 || ctl - i === -3) res += "L";
      }
      ctl = i; // 이전의 방향
      res += "A";
      queue.push([nx2, ny2]);
      visited[nx1][ny1] = true;
      visited[nx2][ny2] = true;
      break;
    }
  }
}

// 정답
let dir;
if (sdir === 0) dir = ">";
else if (sdir === 1) dir = "v";
else if (sdir === 2) dir = "<";
else if (sdir === 3) dir = "^";
console.log(sx, sy);
console.log(dir);
console.log(res);
