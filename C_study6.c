/*
2차 방정식의 해 구하기
 문제 예시)
 입력: 1.0 2.0 2.0
 출력: 2차 방정식의 해는 -1.00 +/- j1.0
*/


#include  <stdio.h>
#include  <math.h>

int  main(void)
{
    double  a, b, c, d, e;
    int j;

    scanf_s("%lf", &a);

    scanf_s("%lf", &b);

    scanf_s("%lf", &c);

    if (a == 0)
    {
        printf("x = %f \n", -c / b);
    }
    else
    {
        d = b * b - 4.0 * a * c;//판별식

        if (d > 0) // 판별식이 0보다 클 때(실근)
        {
            e = sqrt(d);
            printf(" 2차 방적식의 해는 %.2f, %.2f \n", (-b + e) / (2.0 * a), (-b - e) / (2.0 * a));
        }
        else
        {
            if (d == 0) // 판별식이 0일 때(중근)
            {
                printf("2차 방적식의 해는 %.2f \n", (-b) / (2.0 * a));
            }
            else // 판별식이 0보다 작을 때(허근)
            {
                e = sqrt(-d);
                j = 'j';
                printf("2차 방적식의 해는  - %.2f +/- j%.2f \n", (e) / (2.0 * a), (-b) / (2.0 * a));
            }
        }
    }

    return  0;
}



