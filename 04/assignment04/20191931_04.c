#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int num = 0, ah = 0;
char wc1 = 155;
char input[64], num1[20];
FILE * fp2;

//fgets(읽어들일 위치, 읽어올 문자열 크기, stream name)

void subset(int argc) {

	int i, j, num = 0, math = 1 << argc;

	for (i = 0; i < math; i++) {

		printf("[%04d] ", ah);
		fprintf(fp2, "[%04d] ", ah);
		for (j = 0; j < argc; j++) {
			if (i & (1 << j)) num++;
		}
		for (j = 0; j < argc; j++) {
			if (i & (1 << j) && num == 1) {
				printf("%c", num1[j]);
				fprintf(fp2, "%c", num1[j]);
			}
			if (i & (1 << j) && num > 1) {
				printf("%c, ", num1[j]);
				fprintf(fp2, "%c, ", num1[j]);
				num--;
			}
		}
		num = 0;
		if (i == 0)printf("%c", wc1), fprintf(fp2, "%c", wc1);
		ah++;
		printf("\n");
		fprintf(fp2, "\n");
	}
}
int main(int argc, char* argv[])
{
	fp2 = fopen(argv[1], "wt");
	for (int i = 0; i < argc - 2; i++)
	{
		num1[i] = *argv[i + 2];
	}
	subset(argc -2);

	printf("*********************\n");
	fprintf(fp2, "*********************\n");
	printf("kjh99660  SikG  Kim Jeonghyeon\n");
	fprintf(fp2,"kjh99660  SikG  Kim Jeonghyeon\n");
	printf("ID: 20191931\n");
	fprintf(fp2,"ID: 20191931\n");
	printf("*********************\n");
	fprintf(fp2,"*********************\n");
	fclose(fp2);
}
