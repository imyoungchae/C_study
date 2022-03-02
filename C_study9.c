// 포인터 변수를 인수로 사용하여 함수가 외부 변수의 값을 변경 가능(call-by-reference)
// 포인터 변수 사용 예제
// SWAP

#include <stdio.h>
void swap(int*, int*);
void main()
{
	int i = 10, j = 20;
	printf("i = %d, j = %d \n", i, j);
	swap(&i, &j);
	printf("i = %d, j = %d \n", i, j);
}
void swap(int* ip, int* jp)
{
	int temp;
	temp = *ip;
	*ip = *jp;
	*jp = temp;
}
