// 백준 11726
//2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

#include   <stdio.h>
#include   <iostream>
#include   <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int d[1001];

 int dp(int x){
    if (x <= 1) return 1;// 1가지 경우의 수
    if (x == 2) return 2;// 2가지 경우의 수
    if (d[x] != 0) return d[x];// 이미 계산된 값
    else {        //계산 안된 값
           d[x] = ((dp(x - 1) + dp(x - 2)) % 10007);
           return d[x];
         }
     }

int main(void) {
    int x;
    scanf_s("%d", &x);
    printf("%d", dp(x));
    return 0;
    }
      // 타일 : 2*1 ,1*2, 2*2
      // 점화식 : D[n] = D[n-1] + 2 * D[n-2]
    
