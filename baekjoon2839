// 백준 2839번
/*
상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다. 설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.

상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다. 예를 들어, 18킬로그램 설탕을 배달해야 할 때, 3킬로그램 봉지 6개를 가져가도 되지만, 5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.

상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.
*/

#include   <stdio.h>
#include   <iostream>
#include   <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
int main() {
   int n;
   int sugar_sum = 0;
   cin >> n;

   while (n != 0)
   {
      if (n % 5 == 0) {
         ++sugar_sum;
         n -= 5;
         // 복합 대입 연산자 -=
         // : n-=5의 의미는 n=n-5와 같음
      }

      else if (n % 3 == 0) {
         n -= 3;
         // : n-=3의 의미는 n=n-3와 같음
         ++sugar_sum;
      }

      else if (n > 5) {
         n -= 5;
         ++sugar_sum;
      }

      else {
         cout << -1;
         return 0;
      }
   }

   cout << sugar_sum;

   return 0;
}
