#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int num[110];
int num1[110][3];

FILE* fp2, *fp1;
void sumnumber(int num[110][3], int ah);
//fgets(읽어들일 위치, 읽어올 문자열 크기, stream name)

int main(int argc, char* argv[])
{
//	printf("%d\n", sizeof(argv));
//	for (int i = 0; i < sizeof(*argv); i++)printf("%s\n", argv[i]);
	fp2 = fopen(argv[2], "r");//input
	fp1 = fopen(argv[3], "w");//output


	fscanf(fp2,"%d", &num[0]);	
	for (int i = 1; i < num[0] + 1; i++)
	{
		fscanf(fp2,"%d", &num[i]);
	}//input

	for (int i = 0; i < num[0]; i++)
	{
		num1[i][0] = num[i+1];
		num1[i][1] = i;
	}
	int ah = num[0];
	sumnumber(num1, ah);

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
void sumnumber(int num1[110][3], int ah)
{

	for (int i = 0; i < num[0]; i++)
	{
		if (num1[i][1] <= 0 && num1[i][2] == 0)
		{
			printf("[%03d] ", ah);
			fprintf(fp1, "[%03d] ", ah);
			printf("%d\n", num1[i][0]);
			fprintf(fp1, "%d\n", num1[i][0]);
			ah--;
			num1[i][2] = 1;//flag

		}
		else if (num1[i][1] > 0 && num1[i][2] == 0)
		{
			num1[i][0] += num[num1[i][1]];
			num1[i][1]--;
			sumnumber(num1, ah);
		}
		else continue;
	}

}
