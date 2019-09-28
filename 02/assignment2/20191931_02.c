#include<stdio.h>
#include <stdlib.h> 

int numbers = 0;
int num = 0, flag = 0;


int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		char check;
		check = *argv[i];
		if (flag == 1)
		{
			numbers = atoi(argv[i]);
			num += numbers;
			flag = 0;
		}
		if (flag == 2)
		{
			numbers = atoi(argv[i]);
			num -= numbers;
			flag = 0;
		}
		if (check == '+')
		{
			flag = 1;
		}
		if (check == '-')
		{
			flag = 2;
		}
	}
	printf("%d\n", num);
	printf("*********************\n");
	printf("kjh99660  SikG  Kim Jeonghyeon\n");
	printf("ID: 20191931\n");
	printf("*********************\n");
	
}