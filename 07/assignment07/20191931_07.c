#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int number = 0,words_num=0, total=0;
char word[100000][100];
int numbers[100000] = { 0, };
char words[1300];
const char delimeter[100] = ", !?\"\'*.()#\n[]:=/_+-><;-$%&@`~{}|";
FILE* fp2, *fp1;
int main(int argc, char*argv[])
{
	fp2 = fopen(argv[1], "r");//input
	fp1 = fopen(argv[2], "w");//output

	if (fp2 == NULL) {
		printf("파일 읽기 실패\n");
		return 0;
	}
	while (1)
	{
		if (fgets(words, sizeof(words), fp2) == NULL)break;
		char* token = strtok(words, delimeter);

		while (token != NULL)
		{
			_strlwr(token);
			int flag = 0;
			for (int i = 0; i < words_num; i++)
			{		
				if (!strcmp(word[i],token))//있던 단어
				{
					numbers[i]++;
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				token = strtok(NULL, delimeter);
				continue;
			}
			//새로운 단어
			strcpy(word[words_num], token);
			words_num++;
			token = strtok(NULL, delimeter);
		}
	}

	//출력
	for (int i = 0; i < words_num; i++) {
		printf("[%05d] %s (%d)\n", i + 1, word[i], numbers[i]+1);
		fprintf(fp1,"[%05d] %s (%d)\n", i + 1, word[i], numbers[i] + 1);

		total += numbers[i]+1;
	}
	printf("[total] %05d\n", total);
	fprintf(fp1,"[total] %05d\n", total);

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
	
	return 0;
}