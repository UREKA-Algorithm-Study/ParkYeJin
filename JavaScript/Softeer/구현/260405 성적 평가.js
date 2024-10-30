const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

/*
    N명
    0 ~ 1000점
    동점일 경우, 가장 높은 등수
    1 2 3 3 5
*/

// 입력
const N = parseInt(input[0]);
let arr = Array.from(Array(4), () => Array(N + 1).fill(0));

for (let i = 0; i < 3; i++) {
  const row = input[i + 1].split(" ").map(Number);
  for (let j = 0; j < N; j++) {
    arr[i][j] = row[j];
  }
}

// 최종 점수 추가
for (let i = 0; i < N; i++) {
  let sum = 0;
  for (let j = 0; j < 3; j++) {
    sum += arr[j][i];
  }
  arr[3][i] = sum;
}

// 각 대회별 등수 출력
for (let i = 0; i < 4; i++) {
  // 3번 대회 + 최종
  let people = []; // idx, score
  for (let j = 0; j < N; j++) {
    people.push([j, arr[i][j]]);
  }
  // score 기준 내림차순
  people.sort((a, b) => b[1] - a[1]);

  let res = []; // idx, 등수
  let cnt = 0;
  for (let j = 0; j < N; j++) {
    // 이전 값과 같을 경우
    if (j > 0 && people[j - 1][1] === people[j][1]) {
      res.push([people[j][0], j - cnt]);
      cnt++;
    } else {
      res.push([people[j][0], j + 1]);
      cnt = 0;
    }
  }

  // idx 기준으로 res 오름차순 정렬
  res.sort((a, b) => a[0] - b[0]);
  // 각 게임의 등수 출력
  let line = "";
  for (let j = 0; j < N; j++) {
    line += res[j][1] + " ";
  }
  console.log(line);
}
