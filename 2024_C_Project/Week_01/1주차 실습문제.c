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
	scanf("%d", id);
}

void print(struct system* s, int* size, int* id) {
	printf("%d\n", s[*id - 1].in - s[*id - 1].out);
	for (int i = 0; i < *size; i++) printf("%d ", s[i].in - s[i].out);
}

int main() {
	int n, id;
	struct system s[101] = { 0 };
	scan(s, &n, &id);
	print(s, &n, &id);
}
