#include <stdio.h>
/*
 * swap - swap value of @a and @b
 */
#define swap(a, b) \
	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

#define ARRAY_LEN(array) (sizeof(array) / sizeof((array)[0]))

#define ARRAY_WALK(array, len, doit) do{\
    int __loop;     \
    for (__loop = 0; __loop < len; __loop++) {  \
        doit(array[__loop]);   \
    }  \
}while(0)

void insert_sort(int array[], int size)
{
    int i,j;
    for (i = 1; i < size; i++) {
        for (j = i; j >0 && array[j] < array[j - 1]; j--) {
            swap(array[j], array[j - 1]);
        }
    }
}

static inline void print_it(int val)
{
    printf("%d\n", val);
}

int main(int argc, const char *argv[])
{
    int a[] = {2,3,54,5,6,21,8,-1};
    insert_sort(a, ARRAY_LEN(a) );
    ARRAY_WALK(a, ARRAY_LEN(a), print_it);
    return 0;
}
