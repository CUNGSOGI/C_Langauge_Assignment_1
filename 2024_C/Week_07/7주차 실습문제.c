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
		printf("상품 ID: ");
		scanf("%d", &n);
		for (j = 0, k = 0; j < SIZE; j++) {
			if (s[j].id == n) {
				printf("입고량: "), scanf("%d", &n), s[j].in += n;
				printf("판매가격: "), scanf("%d", &n), s[j].sellprice = n;
				printf("\n");
				k++;
				return;
			}
		}
		if (k == 0 && t < SIZE) {
			s[i].id = n;
			printf("상품명: "), getchar(), gets(s[i].name);
			printf("입고량: "), scanf("%d", &n), s[i].in = n;
			printf("판매가격: "), scanf("%d", &n), s[i].sellprice = n;
			printf("\n");
		}
		else {
			printf("ID 갯수 초과");
			Sleep(5000);
			return;
		}
	}
	return;
}

void out(struct system* s) {
	int n, i, S = 0;
	printf("상품ID :");
	scanf("%d", &n);
	for (i = 0; i < SIZE; i++) {
		if (s[i].id == n)
			break;
	}
	if (i == SIZE) {
		printf("없는 ID");
		Sleep(500);
	}
	else {
		printf("판매량: ");
		scanf("%d", &S), s[i].out += S;
	}
	return;
}

void print(struct system* s) {
	int n, i, S = 0;
	printf("상품ID :");
	scanf("%d", &n);
	for (i = 0; i < SIZE - 1; i++) {
		if (s[i].id == n)
			break;
	}
	if (i == SIZE - 1) {
		printf("없는 ID");
		Sleep(500);
	}
	else {
		printf("상품명: %s\n", s[i].name);
		printf("상품가격: %d\n", s[i].sellprice);
		printf("입고량: %d\n", s[i].in);
		printf("판매량: %d\n", s[i].out);
		printf("총판매금액: %d\n", s[i].out * s[i].sellprice);
		printf("\n");
		Sleep(5000);
	}
	return;
}

void allprint(struct system* s) {
	double allout = 0, allin = 0;
	int i, j, m = 0, M = 100;
	printf("재고수량: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", s[i].in - s[i].out);
		allin += s[i].in;
		allout += s[i].out;
	}
	printf("\n총판매량: %.f(판매율 %0.2f%%)\n", allout, (allout / allin) * 100);
	for (i = 0, j = 0; i < SIZE; i++)
		if (m < s[i].out) m = s[i].out, j = i + 1;
	printf("가장 많이 판매된 상품 : ID %d, 상품명: %s, 판매량 %d\n", j, s[j-1].name, m);
	for (i = 0, j = 0; i < SIZE; i++)
		if (M > s[i].out) M = s[i].out, j = i + 1;
	printf("가장 적게 판매된 상품 : ID %d, 상품명: %s, 판매량 %d\n", j, s[j-1].name, M);
	for (i = 0; i < SIZE; i++) {
		if (s[i].in - s[i].out <= s[i].in * 0.2)
			printf("상품 ID %d : 상품명: %s 재고부족(%d)\n", i + 1, s[i].name, s[i].in - s[i].out);
	}
	Sleep(10000);
	return;
}

int main() {
	int n;
	struct system s[SIZE] = { 0 };
	while (1) {
		system("cls");
		printf("[쇼핑몰 관리 프로그램]\n>원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.개별현황, 4.전체현황, 5.종료)\n>");
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