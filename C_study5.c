//함수의 필요성

#include <stdio.h>
void main()
{
	int i, sum;
	sum = 0;
	for (i = 1; i <= 10; i++)
		sum += i;
	printf("sum = % d \n", sum);
	sum = 0;
	for (i = 1; i <= 100; i++)
		sum += i;
	printf("sum = % d \n", sum);
}

// 위와 같은 코드를 아래와 같이 편리하게 나타낼 수 있다

#include <stdio.h>
void sum_ftn(int end); // 함수의 선언
void main()
{
	sum_ftn(10); // 함수의 호출1
	sum_ftn(100); // 함수의 호출2
}
void sum_ftn(int end) // 함수의 정의, int end가 함수의 인수
{
	int i, sum;
	sum = 0;
	for (i = 1; i <= end; i++)
		sum += i;
	printf("sum = % d \n", sum);
}
