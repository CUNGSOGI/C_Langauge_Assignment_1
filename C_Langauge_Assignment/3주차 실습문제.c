#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>

#define N 5

int a[101], b[101], n, ID, i, j, m = 0, M = 100;
double sa = 0, st = 0;

void On() {
	printf("�԰���� �Է��ϼ���. (1.��ü ��ǰ �԰����, 2.���� ��ǰ)");
	scanf("%d", &n);
	if (n == 1)
		for (i = 1; i <= N; i++) scanf("%d", &a[i]), st += a[i];
	else {
		printf("��ǰID: ");
		scanf("%d", &ID);
		printf("�԰����: ");
		scanf("%d", &n), a[ID] += n, st += n;
	}
	return;
}

void Tw() {
	printf("�Ǹż��� �Է��ϼ���.(1.��ü ��ǰ �Ǹż���, 2.���� ��ǰ)");
	scanf("%d", &n);
	if (n == 1)
		for (i = 1; i <= N; i++) scanf("%d", &b[i]), sa += b[i], a[i] -= b[i];
	else {
		printf("��ǰID: ");
		scanf("%d", &ID);
		printf("�Ǹż���: ");
		scanf("%d", &n), b[ID] += n, sa += n, a[ID] -= n;
	}
	return;
}

void Th() {
	printf("������: ");
	for (i = 1; i <= N; i++) printf("%d ", a[i]);
	printf("\n���Ǹŷ�: %0.f(�Ǹ��� %0.2f)\n", sa, (sa / st) * 100);
	for (i = 1, j = 1; i <= N; i++) if (m < b[i]) m = b[i], j = i;
	printf("�ִ�: ID %d,�Ǹŷ� %d\n", j, m);
	for (i = 1, j = 1; i <= N; i++) if (M > b[i]) M = b[i], j = i;
	printf("�ּ�: ID %d,�Ǹŷ� %d\n", j, M);
	for (i = 1; i <= N; i++) if (a[i] <= 2) printf("��ǰ ID %d : ������(%d)\n", i, a[i]);
	Sleep(10000);
	return;
}

int main() {
	while (N != 4) {
		system("cls");
		printf("���ϴ� �޴��� �����ϼ���.(1.�԰�, 2.�Ǹ�, 3.��ǰ��Ȳ, 4.����)");
		scanf("%d", &n);
		if (n == 1)
			On();
		else if (n == 2)
			Tw();
		else if (n == 3)
			Th();
	}
}