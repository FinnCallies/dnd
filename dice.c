#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int dice_count = 1;
    int dice_size = 6;
    int bonus = 0;
    int count = 1;
    int sum = 0;

    srand(time(NULL));

    if (argc < 2) {
        printf("usage: %s [count] [dice_count]W[dice_size][+/-bonus]\n", argv[0]);
        printf("\texample: %s 3 2W4+1\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc > 2)
        count = atoi(argv[1]);

    if (strchr(argv[argc - 1], '+') != NULL) {
        if (sscanf(argv[argc - 1], "%dw%d+%d", &dice_count, &dice_size, &bonus) != 3) {
            fprintf(stderr, "Error: parsing argument \"%s\"\n", argv[argc - 1]);
            exit(EXIT_FAILURE);
        }
    } else if (strchr(argv[argc - 1], '-') != NULL) {
        if (sscanf(argv[argc - 1], "%dw%d-%d", &dice_count, &dice_size, &bonus) != 3) {
            fprintf(stderr, "Error: parsing argument \"%s\"\n", argv[argc - 1]);
            exit(EXIT_FAILURE);
        } else {
            bonus = bonus * -1;
        }
    } else {
        if (sscanf(argv[argc - 1], "%dw%d", &dice_count, &dice_size) != 2) {
            fprintf(stderr, "Error: parsing argument \"%s\"\n", argv[argc - 1]);
            exit(EXIT_FAILURE);
        }
    }


    for (int i = 0; i < count; i++) {
        for (int j = 0; j < dice_count; j++) {
            sum += (rand() % dice_size) + 1;
        }
        sum += bonus;
        printf("%2d/%2d: %4d\n", i + 1, count, sum);
        sum = 0;
    }
}
