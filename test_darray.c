#include <stdio.h>
#include "dynamic_array.h"

int main(void){
    DynamicArr *test = create_array(32);
    int nums[] = {2, 4, 5, 4, 11, 8, 21, 100, 37, 3};
    for (int i = 0; i < 10; i ++){
        push_array(test, nums[i]);
        print_array(test);
    }
    print_array(test);
    return 0;
}
