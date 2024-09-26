#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define N 6

int a[N] = { 0 }, b[N] = { 0 }, n, ID, i, j, m = 0, M = 100;
double sa = 0, st = 0;
char A[N][100];

void On() {
	printf("입고수량 입력하세요. (1.전체 상품 입고수량, 2.개별 상품)");
	scanf("%d", &n);
	if (n == 1)
		for (i = 1; i < N; i++) scanf("%d", &a[i]), st += a[i];
	else {
		printf("상품ID: ");
		scanf("%d", &ID);
		printf("입고수량: ");
		scanf("%d", &n), a[ID] += n, st += n;
	}
	return;
}

void Tw() {
	printf("판매수량 입력하세요.(1.전체 상품 판매수량, 2.개별 상품)");
	scanf("%d", &n);
	if (n == 1)
		for (i = 1; i < N; i++) scanf("%d", &b[i]), sa += b[i], a[i] -= b[i];
	else {
		printf("상품ID: ");
		scanf("%d", &ID);
		printf("판매수량: ");
		scanf("%d", &n), b[ID] += n, sa += n, a[ID] -= n;
	}
	return;
}

void Th() {
	printf("재고수량: ");
	for (i = 1; i < N; i++) printf("%d ", a[i]);
	printf("\n총판매량: %0.f(판매율 %0.2f)\n", sa, (sa / st) * 100);
	for (i = 1, j = 1; i < N; i++) if (m < b[i]) m = b[i], j = i;
	printf("가장 많이 판매된 상품: ID %d,상품명: %s, 판매량 %d\n", j, A[j], m);
	for (i = 1, j = 1; i < N; i++) if (M > b[i]) M = b[i], j = i;
	printf("가장 적게 판매된 상품: ID %d,상품명: %s, 판매량 %d\n", j, A[j], M);
	for (i = 1; i < N; i++) if (a[i] <= 2) printf("상품 ID %d: 상품명:%s 재고부족(%d)\n", i, A[i], a[i]);
	Sleep(10000);
	return;
}
void fo() {
	getchar();
	for (i = 1; i < N; i++) {
		printf("ID %d 상품명:", i);
		gets(A[i]);
	}
	return;
}

int main() {
	while (n != 5) {
		system("cls");
		printf("원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.상품현황, 4.상품명 입력, 5.종료)");
		scanf("%d", &n);
		if (n == 1)
			On();
		else if (n == 2)
			Tw();
		else if (n == 3)
			Th();
		else if (n == 4)
			fo();
	}
}

/*
8 5 3 4 9
5 2 1 4 4
*/