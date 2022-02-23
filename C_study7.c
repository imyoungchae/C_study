# Switch-case문

#include <stdio.h>
void main()
{
	int key_in;
	printf("키보드 입력은 ? (1~5)");
		scanf_s("%d", &key_in); // scanf_s 안의 변수 받을 때 앞에 &써준다
	switch (key_in)
	{
	case 1: printf("1번 입력 \n"); break;
	case 2: printf("2번 입력 \n"); break;
	case 3: printf("3번 입력 \n"); break;
	case 4: printf("4번 입력 \n"); break;
	case 5: printf("5번 입력 \n"); break;
	default: printf("입력 오류 \n");
	}
}

/*
Switch-case문:
if문 중 모든 조건식에 == 연산자가 사용되는 key scan 루틴 등 변수가 특정 값만을 가질 수 있는 경우 사용

switch(조건변수)
{
    case 레이블1:
         문장1;
         break;
    case 레이블2:
         문장2;
         break;
         .
         .
         .
    case 레이블n:
         문장n;
         break;
    default:
         문장 n+1;
 }
 
 Q. if-else문으로 바꾸면?
 
 #include <stdio.h>
void main()
{
	int key_in;
	printf("키보드 입력은 ? (1~5)");
		scanf_s("%d", &key_in);
		if(key_in == 1)
		{
			printf("1번 입력 \n");
		}
		else if(key_in == 2)
		{
			printf("2번 입력 \n");
		}
		else if (key_in == 3)
		{
			printf("3번 입력 \n");
		}
		else if (key_in == 4)
		{
			printf("4번 입력 \n");
		}
		else
		{
			printf("5번 입력 \n");
		}
}
*/
