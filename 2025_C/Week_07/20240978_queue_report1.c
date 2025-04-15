#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>

#define SIZE 30 // ť�� ũ��

typedef struct {
	int data[SIZE];  // ������ ũ���� �迭
	int front;  // ť�� ù ��° ��� �ε���
	int rear;   // ť�� ������ ��� �ε���
} LinearQueue;

// �ʱ�ȭ �Լ�
void initQueue(LinearQueue* q) {
	q->front = 0;
	q->rear = -1;  // rear�� -1�� �����Ͽ� ù ��° ���� �� 0�� �ǵ��� ��
}

// ť�� ��� �ִ��� Ȯ��
bool isEmpty(LinearQueue* q) {
	return q->rear < q->front;  // rear�� front���� ������ ��� ����
}

// ť�� ���� á���� Ȯ��
bool isFull(LinearQueue* q) {
	return q->rear == SIZE - 1;  // rear�� �迭 ���� �����ϸ� ���� ��
}

// ���� �Լ�
bool enqueue(LinearQueue* q, int value) {
	if (isFull(q)) {
		printf("ť�� ���� á���ϴ�.\n");
		return false;
	}
	q->rear++;
	q->data[q->rear] = value;  // rear ��ġ�� ������ �߰�
	return true;
}

// ���� �Լ�
int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("ť�� ��� �ֽ��ϴ�.\n");
		return -1;  // ť�� ��� ���� �� -1 ��ȯ
	}
	int value = q->data[q->front];
	q->front++;
	return value;
}

int main() {
	LinearQueue q;
	initQueue(&q);
	while (1) {
		int n, value;
		printf("\n--- ���� �޴� ---\n1. ����\n2. ����\n3. ť ������ ���\n4. ����\n�޴��� �����ϼ���: ");
		scanf("%d", &n);

		switch (n) {
		case 1:  // Push
			printf("ť�� �߰��� ���� �Է��ϼ���: ");
			scanf("%d", &value);
			printf("Eequeue: %d\n", value, enqueue(&q, value));
			break;
		case 2:  // Pop
			printf("Dequeue: %d\n", dequeue(&q));
			break;
		case 3:  // Display
			while (!isEmpty(&q)) {
				printf("%d \n", dequeue(&q));  // ť�� ����� ������ ������ ���
			}
			break;
		case 4:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		default:
			printf("�߸��� �����Դϴ�! 1���� 4 ������ ���ڸ� �Է����ּ���.\n");
		}
	}

	return 0;
}