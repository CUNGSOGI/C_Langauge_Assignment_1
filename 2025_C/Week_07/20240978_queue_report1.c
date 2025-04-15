#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>

#define SIZE 30 // 큐의 크기

typedef struct {
	int data[SIZE];  // 고정된 크기의 배열
	int front;  // 큐의 첫 번째 요소 인덱스
	int rear;   // 큐의 마지막 요소 인덱스
} LinearQueue;

// 초기화 함수
void initQueue(LinearQueue* q) {
	q->front = 0;
	q->rear = -1;  // rear를 -1로 설정하여 첫 번째 삽입 시 0이 되도록 함
}

// 큐가 비어 있는지 확인
bool isEmpty(LinearQueue* q) {
	return q->rear < q->front;  // rear가 front보다 작으면 비어 있음
}

// 큐가 가득 찼는지 확인
bool isFull(LinearQueue* q) {
	return q->rear == SIZE - 1;  // rear가 배열 끝에 도달하면 가득 참
}

// 삽입 함수
bool enqueue(LinearQueue* q, int value) {
	if (isFull(q)) {
		printf("큐가 가득 찼습니다.\n");
		return false;
	}
	q->rear++;
	q->data[q->rear] = value;  // rear 위치에 데이터 추가
	return true;
}

// 삭제 함수
int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어 있습니다.\n");
		return -1;  // 큐가 비어 있을 때 -1 반환
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
		printf("\n--- 스택 메뉴 ---\n1. 삽입\n2. 삭제\n3. 큐 데이터 출력\n4. 종료\n메뉴를 선택하세요: ");
		scanf("%d", &n);

		switch (n) {
		case 1:  // Push
			printf("큐에 추가할 값을 입력하세요: ");
			scanf("%d", &value);
			printf("Eequeue: %d\n", value, enqueue(&q, value));
			break;
		case 2:  // Pop
			printf("Dequeue: %d\n", dequeue(&q));
			break;
		case 3:  // Display
			while (!isEmpty(&q)) {
				printf("%d \n", dequeue(&q));  // 큐가 비어질 때까지 데이터 출력
			}
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			return 0;
		default:
			printf("잘못된 선택입니다! 1에서 4 사이의 숫자를 입력해주세요.\n");
		}
	}

	return 0;
}