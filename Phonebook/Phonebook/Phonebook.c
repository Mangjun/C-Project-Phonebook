#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_menu();

struct phone {
	char name[10];
	char hp[14];
	int year;
};

int main()
{
	struct phone ph[100] = { NULL };
	int sel, i, cnt = 0;
	FILE* fp = NULL;
	char choose[10]; // 검색 문자열
	char name[10]; // 검색할 이름
	char hp[14]; // 검색할 전화번호

	while (1) {
		print_menu();
		scanf("%d", &sel);
		switch (sel)
		{
		case 1:
			fp = fopen("phonebook.txt", "a+");
			if (fp == NULL) {
				printf("파일 열기 실패");
				return 1;
			}
			cnt = 0;
			while (!feof(fp)) {
				fscanf(fp, "%s %s %d", ph[cnt].name, ph[cnt].hp, &ph[cnt].year);
				if (ph[cnt].year == NULL) {
					break;
				}
				cnt++;
			}
			if (cnt > 100) {
				printf("더이상 입력할 수 없습니다.\n");
				return -1;
			}
			printf("이름: ");
			scanf("%s", ph[0].name);
			fprintf(fp, "%s", ph[0].name);
			printf("전화번호: ");
			scanf("%s", ph[0].hp);
			fprintf(fp, " %s", ph[0].hp);
			printf("생년월일: ");
			scanf("%d", &ph[0].year);
			fprintf(fp, " %d\n", ph[0].year);
			printf("추가되었습니다.\n");
			fclose(fp);
			break;
		case 2:
			fp = fopen("phonebook.txt", "r");
			if (fp == NULL) {
				printf("파일 열기 실패");
				return 1;
			}
			cnt = 0;
			while (!feof(fp)) {
				fscanf(fp, "%s %s %d", ph[cnt].name, ph[cnt].hp, &ph[cnt].year);
				if (ph[cnt].year == NULL) {
					break;
				}
				cnt++;
			}
			printf("이름 전화번호 중 검색할 것을 고르세요: ");
			scanf("%s", choose);
			if (strcmp(choose, "이름") == 0) {
				printf("이름을 검색하겠습니다.\n");
				printf("이름: ");
				scanf("%s", name);
				for (i = 0; i < 100; i++) {
					if (strcmp(ph[i].name, name) == 0) {
						printf("\n이름: %s\n전화번호: %s\n생년월일: %d\n", ph[i].name, ph[i].hp, ph[i].year);
						break;
					}
				}
				if (i == 100) {
					printf("일치하는 자료가 없습니다.\n");
				}
			}
			else if (strcmp(choose, "전화번호") == 0) {
				printf("전화번호를 검색하겠습니다.\n");
				printf("전화번호: ");
				scanf("%s", hp);
				for (i = 0; i < 100; i++) {
					if (strcmp(ph[i].hp, hp) == 0) {
						printf("\n이름: %s\n전화번호: %s\n생년월일: %d\n", ph[i].name, ph[i].hp, ph[i].year);
						break;
					}
				}
				if (i == 100) {
					printf("일치하는 자료가 없습니다.\n");
				}
			}
			else {
				printf("잘못 입력하였습니다. 이름, 전화번호 중 하나만 입력하세요\n");
			}
			fclose(fp);
			break;
		case 3: 
			fp = fopen("phonebook.txt", "r");
			cnt = 0;
			while (!feof(fp)) {
				fscanf(fp, "%s %s %d", ph[cnt].name, ph[cnt].hp, &ph[cnt].year);
				if (ph[cnt].year == NULL) {
					break;
				}
				cnt++;
			}
			printf("\n--------전화번호부-------\n\n");
			for (i = 0; i < cnt; i++) {
				printf("-------------------------\n");
				printf("이름: %s\n전화번호: %s\n생년월일: %d\n", ph[i].name, ph[i].hp, ph[i].year);
				printf("-------------------------\n");
			}
			break;
		case 4:
			printf("종료하겠습니다.\n");
			return -1;
		default:
			printf("잘못 입력하였습니다. 1~4사이의 숫자만 입력하세요.\n");
			break;
		}
	}
}

void print_menu()
{
	printf("\n--------------------\n");
	printf("1. 전화번호 추가\n");
	printf("--------------------\n");
	printf("2. 전화번호 검색\n");
	printf("--------------------\n");
	printf("3. 전화번호부 보기\n");
	printf("--------------------\n");
	printf("4. 종료\n");
	printf("숫자를 입력하세요: ");
}