#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int n, id, a[101][101];
	scanf("%d", &n);
	scanf("%d", &id);
	for (int i = 0; i < n; i++) scanf("%d", &a[id][i]);
	for (int i = 0, j = 0; i < n; i++) {
		scanf("%d", &j);
		a[id][i] -= j;
	}
	for (int i = 0; i < n; i++) printf("%d ", a[id][i]);
}