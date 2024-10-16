#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>
#define SIZE 5

typedef struct system {
	int in;
	int out;
};

void in(struct system* s) {
	int n, S = 0;
	printf("입고수량 입력하세요.(1.전체 상품 입고수량, 2.개별 상품)\n> ");
	scanf("%d", &n);
	if (n == 1)
		for (int i = 0; i < SIZE; i++)
			scanf("%d", &s[i].in);
	else if (n == 2) {
		printf("상품ID:");
		scanf("%d", &n);
		printf("\n");
		printf("입고수량:");
		scanf("%d", &S), s[n - 1].in += S;
	}
	return;
}

void out(struct system* s) {
	int n, S = 0;
	printf("판매수량 입력하세요.(1.전체 상품 판매수량, 2.개별 상품)\n> ");
	scanf("%d", &n);
	if (n == 1)
		for (int i = 0; i < SIZE; i++)
			scanf("%d", &s[i].out);
	else if (n == 2) {
		printf("상품ID:");
		scanf("%d", &n);
		printf("\n");
		printf("판매수량:");
		scanf("%d", &S), s[n - 1].out += S;
	}
	return;
}

void print(struct system* s) {
	double allout = 0, allin = 0;
	int i, j, m = 0, M = 100;
	printf("재고수량: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", s[i].in - s[i].out);
		allin += s[i].in;
		allout += s[i].out;
	}
	printf("\n총판매량: %.f(판매율 %0.2f)\n", allout, (allout / allin) * 100);
	for (i = 0, j = 0; i < SIZE; i++)
		if (m < s[i].out) m = s[i].out, j = i + 1;
	printf("가장 많이 판매된 상품 : ID %d,판매량 %d\n", j, m);
	for (i = 0, j = 0; i < SIZE; i++)
		if (M > s[i].out) M = s[i].out, j = i + 1;
	printf("가장 적게 판매된 상품 : ID %d,판매량 %d\n", j, M);
	for (i = 0; i < SIZE; i++)
		if (s[i].in - s[i].out <= 2) printf("상품 ID %d : 재고부족(%d)\n", i + 1, s[i].in - s[i].out);
	Sleep(10000);
	return;
}

int main() {
	int n;
	struct system s[SIZE] = { 0 };
	while (1) {
		system("cls");
		printf("[쇼핑몰 관리 프로그램]\n>원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.상품현황, 4.종료)\n>");
		scanf("%d", &n);
		system("cls");
		switch (n) {
		case 1: in(s); break;
		case 2: out(s); break;
		case 3: print(s); break;
		default:
			return 0;
		}
	}
}