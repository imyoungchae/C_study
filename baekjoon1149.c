/*
# 백준 1149
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
*/

#include   <stdio.h>
#include   <iostream>
#include   <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
 
int n;
 int result = 0;
 int dp[1001][3] = { 0, };

 int main() {
   cin >> n;

     for (int i = 1; i <= n; i++) {
       cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
              dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
              dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
              dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
         }
   result = min(dp[n][0], min(dp[n][1], dp[n][2]));
      cout << result;
      }
