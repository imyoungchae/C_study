#배열

#include <stdio.h>
void main()
{
	int M[2][3]; // 2개의 그룹, 그룹별 3개의 원소
	int i, j, sum = 0;
	M[0][0] = 1; M[0][1] = 2; M[0][2] = 3;
	M[1][0] = 10; M[1][1] = 20; M[1][2] = 30;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			sum = sum + M[i][j];
			printf("M[%d][%d] = %d ", i, j, M[i][j]);
		}
		printf("\n");
	}
	printf("총합 = %d \n", sum);
}

/*
	M[0][0] = 1; M[0][1] = 2; M[0][2] = 3;
	M[1][0] = 10; M[1][1] = 20; M[1][2] = 30;
  부분은
  int M[2][3] = {{1,2,3},{10,20,30}}; 으로 초기화 가능
 */