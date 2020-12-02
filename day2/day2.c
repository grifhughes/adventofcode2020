#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 40
#define PASSWORD_LEN 20

// helpers
size_t in_range(size_t n, size_t min, size_t max)
{
    return min <= n && n <= max;
}

size_t count_occurrences(char c, char *s)
{
    size_t count = 0;
    for(char *a = s; *a; ++a) {
        if(*a == c)
            ++count;
    }
    return count;
}

// answers
size_t part1(char target, char *password, size_t min, size_t max)
{
    size_t target_count = count_occurrences(target, password);
    if(!in_range(target_count, min, max))
        return 0;
    return 1;
}

size_t part2(char target, char *password, size_t min, size_t max)
{
    char at_min = password[min - 1], at_max = password[max - 1];
    if(at_min == target && at_max == target)
        return 0;
    else if(at_min == target || at_max == target)
        return 1;
    else
        return 0;
}

int main(void)
{
    char buf[LINE_LEN];
    char password[PASSWORD_LEN];
    char target = 0;
    size_t min = 0, max = 0, valid_p1 = 0, valid_p2 = 0;

    FILE *fp = fopen("inputs.txt", "r");
    if(!fp) {
        exit(-1);
    }
    while(fgets(buf, sizeof buf, fp) != 0) {
        sscanf(buf, "%zu-%zu %c: %s\n", &min, &max, &target, password);
        valid_p1 += part1(target, password, min, max);
        valid_p2 += part2(target, password, min, max);
    }
    fclose(fp);
    
    printf("%zu\n%zu\n", valid_p1, valid_p2);
}
