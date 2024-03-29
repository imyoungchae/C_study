// 백준 1463 
/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/
#include   <stdio.h>
#include   <iostream>
#include   <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int min(int a, int b) {
  return a > b ? b : a;
   }

int main() {

int arr[1000001] = {0, };
int i,N;
scanf("%d", &N);
arr[1] = 0;
  for(i = 2; i <= N; i++) {
      arr[i] = arr[i-1] + 1;
      if (i % 2 == 0) arr[i] = min(arr[i], arr[i/2] + 1);
      if (i % 3 == 0) arr[i] = min(arr[i], arr[i/3] + 1);
   }

printf("%d\n", arr[N]);
return 0;
}
