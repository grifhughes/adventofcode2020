#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_NUMS 200

int main(void)
{
    FILE *fp = fopen("inputs.txt", "r");
    if(!fp) {
        exit(-1);
    }

    size_t set[TOTAL_NUMS] = {0};
    size_t num = 0;
    while(fscanf(fp, "%zu\n", &num) == 1) {
        set[num % TOTAL_NUMS] = num;
    }
    fclose(fp);

    size_t target = 2020;
    size_t diff = 0;
    clock_t start = clock();
    for(size_t i = 0; i < TOTAL_NUMS; ++i) {
        diff = target - set[i];
        if(set[diff % TOTAL_NUMS] == diff) {
            printf("%zu\n", diff * set[i]);
            break;
        }
    }
    clock_t end = clock();

    double time = ((double)end - start) / CLOCKS_PER_SEC * 1000;
    printf("%lf\n", time);
}
