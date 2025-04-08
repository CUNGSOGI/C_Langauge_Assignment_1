#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int top;
	int capacity;
} Stack;

void initStack(Stack* s, int initialSize) {
	s->data = (int*)malloc(initialSize * sizeof(int));
	if (s->data == NULL) {
		printf("메모리 할당 실패!\n");
		exit(1);
	}
	s->top = -1;
	s->capacity = initialSize;
}

int isFull(Stack* s) {
	return s->top == s->capacity - 1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

void push(Stack* s, int value) {
	if (isFull(s)) {
		printf("Stack overflow! cannot push %d\n", value);
		return;
	}
	s->data[++(s->top)] = value;
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack underflow! cannot pop\n");
		return -1;
	}
	return s->data[(s->top)--];
}

int peek(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty! cannot peek\n");
		return -1;
	}
	return s->data[s->top];
}

void freeStack(Stack* s) {
	free(s->data);
}

int main() {
	Stack s;
	int n = 0, a = 0;
	char str[100];
	printf("문자열을 입력하시오: ");
	gets_s(str, sizeof(str));
	int l = 0;
	while (str[l] != '\0') l++;
	initStack(&s, l);
	printf("거꾸로 출력된 문자열: ");
	for (int i = 0; i < l; i++)
		push(&s, str[i]);
	while (isEmpty(&s) == 0) {
		printf("%c", peek(&s));
		pop(&s);
	}
	freeStack(&s);
}