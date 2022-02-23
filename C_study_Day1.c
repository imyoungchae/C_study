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

