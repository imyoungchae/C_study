//백준 1003 피보나치 함수
#include   <stdio.h>
#include   <iostream>
#include   <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
      int n;
      cin >> n;
      vector<int>zero(41, 0);
      vector<int>one(41, 0);
      //zero[0]~zero[40] 이므로 41
      int x;
      while (n--) {
         zero[0] = 1;//피보나치 수 첫번째 수 초기화 완료
         one[1] = 1; //피보나치 수 두번째 수 초기화 완료
         cin >> x;
         for (int i = 2; i <= x; i++) {// 0번째와 1번째 항에 대한 값은 이미 주어져 있음
            zero[i] = zero[i - 1] + zero[i - 2];
            one[i] = one[i - 1] + one[i - 2];
         }
         cout << zero[x] << " " << one[x] << endl;
      }
      return 0;
   }
