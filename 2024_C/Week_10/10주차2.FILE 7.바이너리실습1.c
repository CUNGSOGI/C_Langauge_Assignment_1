#include<stdio.h>
#define SIZE 100

int main() {
	char input[SIZE];
	FILE* fp = NULL;
	if ((fp = open("output.bin", "wb")) == NULL) {
		printf("error...");
		return 0;
	}
	gets(input);
	fwrite(input, strlen(input), 1, fp);
	fclose(fp);
	return 0;

}