const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

/*
  어떤 수가 다른 수 두개의 합 가능
  Ai 10^9
*/

const N = Number(input[0]);
const A = input[1].split(" ").map(Number);

// 정렬
A.sort((a, b) => a - b);

// 투포인터
let res = 0;
for (let i = 0; i < N; i++) {
  let left = 0;
  let right = N - 1;

  while (left < right) {
    let sum = A[left] + A[right];

    if (sum === A[i]) {
      // 본인일 경우 무시
      if (left === i) left++;
      else if (right === i) right--;
      else {
        res++;
        break;
      }
    } else if (sum < A[i]) {
      left++;
    } else if (sum > A[i]) right--;
  }
}

console.log(res);
