#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int i = 0, j = 0, n, M = 100, m = 0, a[101], b[101];
	double t = 0, t1 = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]), t1 += a[i];
	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		a[i] -= b[i];
		t += b[i];
	}

	printf("������: ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n���Ǹŷ�: %d(�Ǹ��� %0.2f)\n", t, (t / t1) * 100);
	for (i = 0, j = 0; i < n; i++) if (m < b[i]) m = b[i], j = i + 1;
	printf("�ִ�: ID %d,�Ǹŷ� %d", j, m);
	for (i = 0, j = 0; i < n; i++) if (M > b[i]) M = b[i], j = i + 1;
	printf("�ּ�: ID %d,�Ǹŷ� %d\n", j, M);
	for (i = 0; i < n; i++) if (a[i] <= 2) printf("��ǰ ID %d : ������(%d)\n", i + 1, a[i]);

}