#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define N 5
//��ǰID, ��ǰ��, �԰�, �Ǹŷ�, �ǸŰ���, ���Ǹűݾ�
int a[N + 1][N + 1], n, i;

void On() {
	for (int i = 0; i < N; i++) {
		printf("��ǰ ID: "), scanf("%d", &n), a[0][i] = n;
		printf("��ǰ��: "), scanf("%d", &n), a[1][i] = n;
		printf("�԰�: "), scanf("%d", &n), a[2][i] = n;
		printf("�ǸŰ���: "), scanf("%d", &n), a[4][i] = n;
		printf("\n");
	}
	return;
}

void Tw() {
	int t = 0;
	printf("��ǰID: "), scanf("%d", &n);
	for (i = 0; i < N; i++) {
		if (a[0][i] == n) {
			t++;
			break;
		}
	}
	if (t != 0) {
		printf("�Ǹŷ�: "), scanf("%d", &n), a[3][i] += n;
		a[5][i] = a[3][i] * a[4][i];
	}
	else
		printf("�������� �ʴ� ID�Դϴ�");
	return;
}

void Th() {
	printf("��ǰ ��ȣ");
	scanf("%d", &n);
	printf("��ǰID: %d\n ��ǰ��: %d\n �԰�: %d\n �Ǹŷ�: %d\n �ǸŰ���: %d\n ���Ǹűݾ�: %d\n", a[0][n - 1], a[1][n - 1], a[2][n - 1], a[3][n - 1], a[4][n - 1], a[5][n - 1]);
	Sleep(5000);
	return;
}
void fo() {
	for (i = 0; i < N; i++)
		printf("��ǰID: %d\n ��ǰ��: %d\n �԰�: %d\n �Ǹŷ�: %d\n �ǸŰ���: %d\n ���Ǹűݾ�: %d\n\n", a[0][i], a[1][i], a[2][i], a[3][i], a[4][i], a[5][i]);
	Sleep(10000);
	return;
}

int main() {
	while (n != 5) {
		system("cls");
		printf("���ϴ� �޴��� �����ϼ���.(1.�԰�, 2.�Ǹ�, 3.������Ȳ, 4.��ü��Ȳ, 5.����)");
		scanf("%d", &n);
		if (n == 1)
			On();
		else if (n == 2)
			Tw();
		else if (n == 3)
			Th();
		else if (n == 4)
			fo();
		else if (n == 5)
			return 0;
		n = 0;
	}
}

/*
8 5 3 4 9
5 2 1 4 4
*/