#include <stdio.h>

int main(void){
    int v;
    int *a = &v;
    *a = 5;
    printf("%d, %d, %p\n", v, (*a), a);
    return 0;
}
