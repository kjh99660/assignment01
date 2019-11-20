#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int number;
char output[720][7], num[6]; int num1 = 0, num2 = 0;;
FILE* fp2, * fp1;
int factorial(int n)
{
	if (n == 1)return 1;
	if (n == 0)return 1;

	return n * factorial(n - 1);
}
void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void compo(int number, char num[], int num1)
{
	if (number == 0) {
		strcpy(output[num2], num);
		num2++;
	}
	else
	{
		for (int i = 0; i < number; i++) {
				swap(&num[i], &num[number-1]);
				compo(number-1, num, num1);
				swap(&num[i], &num[number-1]);
		}
	}
}

int main(int argc, char* argv[])
{
	char str[7];
	fp2 = fopen(argv[2], "r");//input
	fp1 = fopen(argv[3], "w");//output

	fscanf_s(fp2, "%d\n", &number);
	for (int i = 0; i < number; i++)
	{
		fscanf_s(fp2, "%c\n", &num[i], 1);
	}//input

	compo(number, num, num1);

	for (int i = 0; i < factorial(number); i++){
		for (int j = i + 1; j < factorial(number); j++) {
			if (strcmp(output[i], output[j]) > 0)
			{
				strcpy(str, output[i]);
				strcpy(output[i], output[j]);
				strcpy(output[j], str);
			}
		}
	}

	for (int i = 0; i < factorial(number); i++) {
		printf("[%03d] %s\n",i+1, output[i]);
		fprintf(fp1,"[%03d] %s\n", i + 1, output[i]);
	}//output


	printf("*********************\n");
	fprintf(fp1, "*********************\n");
	printf("kjh99660  SikG  Kim Jeonghyeon\n");
	fprintf(fp1, "kjh99660  SikG  Kim Jeonghyeon\n");
	printf("ID: 20191931\n");
	fprintf(fp1, "ID: 20191931\n");
	printf("*********************\n");
	fprintf(fp1, "*********************\n");
	fclose(fp2);
	fclose(fp1);
}