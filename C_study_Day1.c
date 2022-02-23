#include <stdio.h>
void main()
{
	int sensor;

	scanf_s("%d", &sensor);
	printf("센서값:%d\n", sensor);

	if (sensor >= 21 && sensor <= 30) printf("High\n");
	else if (sensor >= 11 && sensor <= 20) printf("Normal \n");
	else if (sensor >= 1 && sensor <= 10) printf("Low \n");

	else printf("Error \n");
	
}
/*
정수인 센서 값(1~30)을 입력받아 그에 해당하는 문자를 출력

 센서값   |  출력
 ---------------------
  1~10    |   Low
  11~20   |   Normal
  21~30   |   High
  기타 값 |   Error

 문제 예시)
 입력: 센서값 : 15
 출력: Normal




- 쓰인 개념
1) if - else문
    if (조건식1)
    {
        실행문1;
        실행문2;
    }
    else if(조건식2)
    {
        실행문1;
        실행문2;
    }
    else
    {
        실행문1;
        실행문2;
    }

 2) 논리(logic) 연산자
     X&&Y / AND(논리곱) / 조건식 X와 Y 모두 만족해야 1
     X||Y / OR(논리합)  / 조건식 X,Y 중 하나만 만족하면 1
     ! / NOT(논리 부정) / 조건식 결과 값 toggle
*/
