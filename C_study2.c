#중첩 for문

#include <stdio.h>
 void main( )
{
    int i, j;
    for(i = 1; i <= 5; i++)
    {
      for(j = 1; j <= i; j++)
      {
          printf("*");
       }
        printf("\n");
     }
}

/*
출력:
*
**
***
****
*****

Q. print("%d",i)로 바꾸면?
출력:
1
22
333
4444
55555

Q2. print("%d",j)로 바꾸면?
출력:
1
12
123
1234
12345

Q3.출력 모양이 거꾸로 나오게 하려면?
#include <stdio.h>
void main()
{
    int i, j;
    for (i = 5; i >= 1; i--) // i 부분의 for문 수정
    {
        for (j = 1; j <= i; j++) 
        {
            printf("*");
        }
        printf("\n");
    }
}
*/

