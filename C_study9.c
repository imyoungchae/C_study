//조건부 컴파일 기법

//def_common.h로 저장(헤더파일저장)
#ifdef _CPU_20M
#define _CPU_CLK 20
#define timer_value 100
#else
#define _CPU_CLK 16
#define timer_value 125
#endif

//main.c로 저장
#define _CPU_20M
#include <stdio.h>
#include "def_common.h"
void main( )
{
printf("시스템 클락 주파수 = %d MHz \n", _CPU_CLK);
printf("타이머 설정치 = %d \n", timer_value);
} 

/*
- 지역(local) 변수와 전역(global) 변수: 전역변수는 함수 밖에서 선언
- 내부 변수와 외부(external) 변수
: 외부 파일에서도 공통 사용하는 변수 예) extern int sum = 0;
- 자동(auto) 변수와 정적(static) 변수 : 예) staic int x

const : 변수 선언 앞에 오면 상수가 된다. 상수형 배열 정의에 유용
예) const float pi = 3.14(#define pi 3.14와 같은 효과)
*/
