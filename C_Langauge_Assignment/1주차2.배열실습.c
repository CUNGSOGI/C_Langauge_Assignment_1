#include <stdio.h>
#include <stdlib.h>

int main() {
    int number=0;
    srand(time(NULL));
    for(int i=0;i<10;i++){
        number = rand();
        printf("number = %d\n",number);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number[10];
    srand(time(NULL));
    
    for(int i=0;i<10;i++)
        number[i]=(rand()%101);
    
    for(int i=0;i<10;i++)
        printf("number = %d\n",number[i]);
    
    return 0;
}
