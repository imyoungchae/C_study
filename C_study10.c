// 2차원 배열의 포인터 사용 예제

#include <stdio.h>
void main( )
{
  int M[2][3] = { {10, 11, 12}, {20, 21, 22} };
  int i, j, num = 0, *p;
  p = M;
  for(i = 0; i < 2; i++)
    {
      for(j = 0; j < 3; j++){
      printf("M[%d][%d] = %d \n", i, j, *(p+num));
      num++;
       }
     }
}

/*
line8의 
p=M;은
p=&M[0][0]로 변경하여도 동일한 출력

또한 line12의
*(p+num)은 
M[i][j]로 변경하여도 동일한 출력
*/
