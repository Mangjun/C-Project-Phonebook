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
	char choose[10]; // �˻� ���ڿ�
	char name[10]; // �˻��� �̸�
	char hp[14]; // �˻��� ��ȭ��ȣ

	while (1) {
		print_menu();
		scanf("%d", &sel);
		switch (sel)
		{
		case 1:
			fp = fopen("phonebook.txt", "a+");
			if (fp == NULL) {
				printf("���� ���� ����");
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
				printf("���̻� �Է��� �� �����ϴ�.\n");
				return -1;
			}
			printf("�̸�: ");
			scanf("%s", ph[0].name);
			fprintf(fp, "%s", ph[0].name);
			printf("��ȭ��ȣ: ");
			scanf("%s", ph[0].hp);
			fprintf(fp, " %s", ph[0].hp);
			printf("�������: ");
			scanf("%d", &ph[0].year);
			fprintf(fp, " %d\n", ph[0].year);
			printf("�߰��Ǿ����ϴ�.\n");
			fclose(fp);
			break;
		case 2:
			fp = fopen("phonebook.txt", "r");
			if (fp == NULL) {
				printf("���� ���� ����");
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
			printf("�̸� ��ȭ��ȣ �� �˻��� ���� ������: ");
			scanf("%s", choose);
			if (strcmp(choose, "�̸�") == 0) {
				printf("�̸��� �˻��ϰڽ��ϴ�.\n");
				printf("�̸�: ");
				scanf("%s", name);
				for (i = 0; i < 100; i++) {
					if (strcmp(ph[i].name, name) == 0) {
						printf("\n�̸�: %s\n��ȭ��ȣ: %s\n�������: %d\n", ph[i].name, ph[i].hp, ph[i].year);
						break;
					}
				}
				if (i == 100) {
					printf("��ġ�ϴ� �ڷᰡ �����ϴ�.\n");
				}
			}
			else if (strcmp(choose, "��ȭ��ȣ") == 0) {
				printf("��ȭ��ȣ�� �˻��ϰڽ��ϴ�.\n");
				printf("��ȭ��ȣ: ");
				scanf("%s", hp);
				for (i = 0; i < 100; i++) {
					if (strcmp(ph[i].hp, hp) == 0) {
						printf("\n�̸�: %s\n��ȭ��ȣ: %s\n�������: %d\n", ph[i].name, ph[i].hp, ph[i].year);
						break;
					}
				}
				if (i == 100) {
					printf("��ġ�ϴ� �ڷᰡ �����ϴ�.\n");
				}
			}
			else {
				printf("�߸� �Է��Ͽ����ϴ�. �̸�, ��ȭ��ȣ �� �ϳ��� �Է��ϼ���\n");
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
			printf("\n--------��ȭ��ȣ��-------\n\n");
			for (i = 0; i < cnt; i++) {
				printf("-------------------------\n");
				printf("�̸�: %s\n��ȭ��ȣ: %s\n�������: %d\n", ph[i].name, ph[i].hp, ph[i].year);
				printf("-------------------------\n");
			}
			break;
		case 4:
			printf("�����ϰڽ��ϴ�.\n");
			return -1;
		default:
			printf("�߸� �Է��Ͽ����ϴ�. 1~4������ ���ڸ� �Է��ϼ���.\n");
			break;
		}
	}
}

void print_menu()
{
	printf("\n--------------------\n");
	printf("1. ��ȭ��ȣ �߰�\n");
	printf("--------------------\n");
	printf("2. ��ȭ��ȣ �˻�\n");
	printf("--------------------\n");
	printf("3. ��ȭ��ȣ�� ����\n");
	printf("--------------------\n");
	printf("4. ����\n");
	printf("���ڸ� �Է��ϼ���: ");
}