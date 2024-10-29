const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

/*
    클러스터 성능, 컴퓨터 수 많아질수록, 각각 성능 올라갈수록 향상 
    성능 가장 낮은 컴퓨터 병목됨

    N대의 컴퓨터 각각 성능 Ai
    성능 d만큼 향상 비용 d^2

    1 컴퓨터 1 업그레이드
    예산 B
*/

// 입력
// 성능수, 예산
const [N, B] = input[0].split(" ").map(Number);
// 각각의 성능
let A = input[1].split(" ").map(Number);

A.sort((a, b) => a - b); // 오름차순 정렬

let left = A[0]; // 가장 낮은 성능값
let right = Math.pow(10, 18); // 가장 높은 성능값

let res = 0;

while (left <= right) {
  let mid = Math.floor((left + right) / 2); // 성능값

  let sum = 0;
  for (let i = 0; i < N; i++) {
    if (A[i] < mid) {
      sum += Math.pow(mid - A[i], 2);
    } else break;
  }

  // 예산 보다 작아야만 성능 업그레이드
  if (sum <= B) {
    left = mid + 1;
    res = mid;
  } else right = mid - 1;
}

console.log(res);
