#include<stdio.h>
#include <wchar.h>

int num = 0, ah = 0;
int numbers[10];
int number;
wchar_t wc1 = L'ик';



void subset(int argc) {

	int i, j, num = 0,math = 1 << argc;

	for (i = 0; i < math; i++) {

		printf("[%04d] ", ah);
		for (j = 0; j < argc; j++) {
			if (i & (1 << j)) num++;
		}
		for (j = 0; j < argc; j++) {
			if (i & (1 << j) && num == 1) {
				printf("%c", numbers[j]);
			}
			if (i & (1 << j) && num > 1) {
				printf("%c, ", numbers[j]);
				num--;
			}
		}
		num = 0;
		if (i == 0)wprintf(L"%c", wc1);
		ah++;
		printf("\n");
	}
}
int main(int argc, char* argv[])
{
	number = argc-1;
	for (int i = 1; i < argc; i++)
	{
		numbers[i-1] = *argv[i];
	}
	subset(argc-1);
	printf("*********************\n");
	printf("kjh99660  SikG  Kim Jeonghyeon\n");
	printf("ID: 20191931\n");
	printf("*********************\n");
}
