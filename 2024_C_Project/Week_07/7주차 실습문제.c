#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define SIZE 5

typedef struct system {
	int id;
	int in;
	int out;
	int sellprice;
	char name[100];
};

void in(struct system* s) {
	int i, j = 0, k = 0, n, t = 0, S = 0;
	for (i = 0; i < SIZE; i++) {
		if (s[i].id != 0) t++;
	}
	for (i = 0; i < SIZE; i++) {
		printf("��ǰ ID: ");
		scanf("%d", &n);
		for (j = 0, k = 0; j < SIZE; j++) {
			if (s[j].id == n) {
				printf("�԰�: "), scanf("%d", &n), s[j].in += n;
				printf("�ǸŰ���: "), scanf("%d", &n), s[j].sellprice = n;
				printf("\n");
				k++;
				return;
			}
		}
		if (k == 0 && t < SIZE) {
			s[i].id = n;
			printf("��ǰ��: "), getchar(), gets(s[i].name);
			printf("�԰�: "), scanf("%d", &n), s[i].in = n;
			printf("�ǸŰ���: "), scanf("%d", &n), s[i].sellprice = n;
			printf("\n");
		}
		else {
			printf("ID ���� �ʰ�");
			Sleep(5000);
			return;
		}
	}
	return;
}

void out(struct system* s) {
	int n, i, S = 0;
	printf("��ǰID :");
	scanf("%d", &n);
	for (i = 0; i < SIZE; i++) {
		if (s[i].id == n)
			break;
	}
	if (i == SIZE) {
		printf("���� ID");
		Sleep(500);
	}
	else {
		printf("�Ǹŷ�: ");
		scanf("%d", &S), s[i].out += S;
	}
	return;
}

void print(struct system* s) {
	int n, i, S = 0;
	printf("��ǰID :");
	scanf("%d", &n);
	for (i = 0; i < SIZE - 1; i++) {
		if (s[i].id == n)
			break;
	}
	if (i == SIZE - 1) {
		printf("���� ID");
		Sleep(500);
	}
	else {
		printf("��ǰ��: %s\n", s[i].name);
		printf("��ǰ����: %d\n", s[i].sellprice);
		printf("�԰�: %d\n", s[i].in);
		printf("�Ǹŷ�: %d\n", s[i].out);
		printf("���Ǹűݾ�: %d\n", s[i].out * s[i].sellprice);
		printf("\n");
		Sleep(5000);
	}
	return;
}

void allprint(struct system* s) {
	double allout = 0, allin = 0;
	int i, j, m = 0, M = 100;
	printf("������: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", s[i].in - s[i].out);
		allin += s[i].in;
		allout += s[i].out;
	}
	printf("\n���Ǹŷ�: %.f(�Ǹ��� %0.2f%%)\n", allout, (allout / allin) * 100);
	for (i = 0, j = 0; i < SIZE; i++)
		if (m < s[i].out) m = s[i].out, j = i + 1;
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ��: %s, �Ǹŷ� %d\n", j, s[j-1].name, m);
	for (i = 0, j = 0; i < SIZE; i++)
		if (M > s[i].out) M = s[i].out, j = i + 1;
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ��: %s, �Ǹŷ� %d\n", j, s[j-1].name, M);
	for (i = 0; i < SIZE; i++) {
		if (s[i].in - s[i].out <= s[i].in * 0.2)
			printf("��ǰ ID %d : ��ǰ��: %s ������(%d)\n", i + 1, s[i].name, s[i].in - s[i].out);
	}
	Sleep(10000);
	return;
}

int main() {
	int n;
	struct system s[SIZE] = { 0 };
	while (1) {
		system("cls");
		printf("[���θ� ���� ���α׷�]\n>���ϴ� �޴��� �����ϼ���.(1.�԰�, 2.�Ǹ�, 3.������Ȳ, 4.��ü��Ȳ, 5.����)\n>");
		scanf("%d", &n);
		system("cls");
		switch (n) {
		case 1: in(s); break;
		case 2: out(s); break;
		case 3: print(s); break;
		case 4: allprint(s); break;
		default:
			return 0;
		}
	}
}