#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++){
        a[i] = 5 - i;
    }
    for (int i = 0; i < 5; i++){
        fprintf(stdout, "a[%d] = %d\n", i, a[i]);
    }
    fprintf(stdout, "%p\n", a);
    return 0;
}
