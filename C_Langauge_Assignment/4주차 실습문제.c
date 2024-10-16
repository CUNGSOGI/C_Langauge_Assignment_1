#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define SIZE 5

typedef struct system {
	int in;
	int out;
	char name[100];
};

void in(struct system* s) {
	int n, S = 0;
	printf("�԰���� �Է��ϼ���.(1.��ü ��ǰ �԰����, 2.���� ��ǰ)\n> ");
	scanf("%d", &n);
	if (n == 1)
		for (int i = 0; i < SIZE; i++)
			scanf("%d", &s[i].in);
	else if (n == 2) {
		printf("��ǰID:");
		scanf("%d", &n);
		printf("�԰����:");
		scanf("%d", &S), s[n - 1].in += S;
	}
	return;
}

void out(struct system* s) {
	int n, S = 0;
	printf("�Ǹż��� �Է��ϼ���.(1.��ü ��ǰ �Ǹż���, 2.���� ��ǰ)\n> ");
	scanf("%d", &n);
	if (n == 1)
		for (int i = 0; i < SIZE; i++)
			scanf("%d", &s[i].out);
	else if (n == 2) {
		printf("��ǰID:");
		scanf("%d", &n);
		printf("�Ǹż���:");
		scanf("%d", &S), s[n - 1].out += S;
	}
	return;
}

void print(struct system* s) {
	double allout = 0, allin = 0;
	int i, j, m = 0, M = 100;
	printf("������: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", s[i].in - s[i].out);
		allin += s[i].in;
		allout += s[i].out;
	}
	printf("\n���Ǹŷ�: %.f(�Ǹ��� %0.2f)\n", allout, (allout / allin) * 100);
	for (i = 0, j = 0; i < SIZE; i++)
		if (m < s[i].out) m = s[i].out, j = i + 1;
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ��: %s, �Ǹŷ� %d\n", j, s[j].name, m);
	for (i = 0, j = 0; i < SIZE; i++)
		if (M > s[i].out) M = s[i].out, j = i + 1;
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ��: %s, �Ǹŷ� %d\n", j, s[j].name, M);
	for (i = 0; i < SIZE; i++) {
		if (s[i].in - s[i].out <= 2)
			printf("��ǰ ID %d : ��ǰ��: %s ������(%d)\n", i + 1, s[i].name, s[i].in - s[i].out);
	}
	Sleep(10000);
	return;
}

void name(struct system* s) {
	getchar();
	for (int i = 0; i < SIZE; i++) {
		printf("ID %d ��ǰ��:", i + 1);
		gets(s[i].name);
	}
	return;
}

int main() {
	int n;
	struct system s[SIZE] = { 0 };
	while (1) {
		system("cls");
		printf("[���θ� ���� ���α׷�]\n>���ϴ� �޴��� �����ϼ���.(1.�԰�, 2.�Ǹ�, 3.��ǰ��Ȳ, 4.��ǰ�� �Է�, 5.����)\n>");
		scanf("%d", &n);
		system("cls");
		switch (n) {
		case 1: in(s); break;
		case 2: out(s); break;
		case 3: print(s); break;
		case 4: name(s); break;
		default:
			return 0;
		}
	}
}