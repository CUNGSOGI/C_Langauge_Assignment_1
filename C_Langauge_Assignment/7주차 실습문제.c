#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define N 5
//상품ID, 상품명, 입고량, 판매량, 판매가격, 총판매금액
int a[N + 1][N + 1], n, i;

void On() {
	for (int i = 0; i < N; i++) {
		printf("상품 ID: "), scanf("%d", &n), a[0][i] = n;
		printf("상품명: "), scanf("%d", &n), a[1][i] = n;
		printf("입고량: "), scanf("%d", &n), a[2][i] = n;
		printf("판매가격: "), scanf("%d", &n), a[4][i] = n;
		printf("\n");
	}
	return;
}

void Tw() {
	int t = 0;
	printf("상품ID: "), scanf("%d", &n);
	for (i = 0; i < N; i++) {
		if (a[0][i] == n) {
			t++;
			break;
		}
	}
	if (t != 0) {
		printf("판매량: "), scanf("%d", &n), a[3][i] += n;
		a[5][i] = a[3][i] * a[4][i];
	}
	else
		printf("존재하지 않는 ID입니다");
	return;
}

void Th() {
	printf("상품 번호");
	scanf("%d", &n);
	printf("상품ID: %d\n 상품명: %d\n 입고량: %d\n 판매량: %d\n 판매가격: %d\n 총판매금액: %d\n", a[0][n - 1], a[1][n - 1], a[2][n - 1], a[3][n - 1], a[4][n - 1], a[5][n - 1]);
	Sleep(5000);
	return;
}
void fo() {
	for (i = 0; i < N; i++)
		printf("상품ID: %d\n 상품명: %d\n 입고량: %d\n 판매량: %d\n 판매가격: %d\n 총판매금액: %d\n\n", a[0][i], a[1][i], a[2][i], a[3][i], a[4][i], a[5][i]);
	Sleep(10000);
	return;
}

int main() {
	while (n != 5) {
		system("cls");
		printf("원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.개별현황, 4.전체현황, 5.종료)");
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