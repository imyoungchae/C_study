# for 반복문 (loop)

#include <stdio.h>
void main( )
{
int i, sum;
sum = 0;
for(i = 1; i <= 10; i++)
{
sum += i; // 증감연산자
}
printf("1부터 10까지 합은 %d \n", sum);
}


/*
- 반복문
:초기값에서 출발하여 증감식을 한번씩 수행하면서
 조건식을 만족하는 동안 {}안 문장들을 반복 수행
 
for(초기값; 조건식; 증감식)
{
    실행문1;
    실행문2;
 }
 
 반복문의 3대 요소
 - 카운터 변수 초기화
 - 조건식
 - 카운터 변수 관리(증가 또는 감소)
 
 
 - 증감연산자
 1) a = a + 1;
 2) a += 1;
 3) a++;
 셋은 모두 같은 결과이며
 변수 a의 값을 1 증가시킨다.
 증감연산자는 전위형과 후위형이 있다.
 */
 
