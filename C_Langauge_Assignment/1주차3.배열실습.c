#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SiZE 100

int main() {
	int number[SIZE];
	int total = 0;
	int max, min;
	float avg = 0.0;
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		number[i] = (rand() % 100) + 1;
	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	for (int i = 0; i < SIZE; i++)
		total += number[i];
	avg = (float)tatal / SIZE;
	max = number[0];
	min = number[0];
	for (int i = 0; i < SIZE; i++) {
		if(max<)
	}
	printf("%f", avg);
	return 0;
}

