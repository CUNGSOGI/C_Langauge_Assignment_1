#pragma warning(disable:4996)
#include <stdio.h>

typedef struct system {
	int in;
	int out;
};

void scan(struct system* s, int* size, int* id) {
	scanf("%d", size);
	for (int i = 0; i < *size; i++) scanf("%d", &s[i].in);
	for (int i = 0; i < *size; i++) scanf("%d", &s[i].out);
}

void print(struct system* s, int* size, int* id) {
	double allout = 0, allin = 0;
	int i, j, m = 0, M = 100;
	printf("재고수량: ");
	for (int i = 0; i < *size; i++) {
		printf("%d ", s[i].in - s[i].out);
		allin += s[i].in;
		allout += s[i].out;
	}
	printf("\n총판매량: %.f(판매율 %0.2f)\n", allout, (allout / allin) * 100);
	for (i = 0, j = 0; i < *size; i++)
		if (m < s[i].out) m = s[i].out, j = i + 1;
	printf("가장 많이 판매된 상품 : ID %d,판매량 %d\n", j, m);
	for (i = 0, j = 0; i < *size; i++)
		if (M > s[i].out) M = s[i].out, j = i + 1;
	printf("가장 적게 판매된 상품 : ID %d,판매량 %d\n", j, M);
	for (i = 0; i < *size; i++)
		if (s[i].in - s[i].out <= 2) printf("상품 ID %d : 재고부족(%d)\n", i + 1, s[i].in - s[i].out);
}

int main() {
	int n, id;
	struct system s[101] = { 0 };
	scan(s, &n, &id);
	print(s, &n, &id);
}