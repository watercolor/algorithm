#include <stdio.h>
#include <stdlib.h>

/*
 * SWAP - swap value of @a and @b, DON'T USE ++,-- with this macro
 */
#define SWAP(a, b) \
	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

/* caculate element numners in a array */
#define ARRAY_LEN(array) (sizeof(array) / sizeof((array)[0]))

/* walk a array and do something */
#define ARRAY_WALK(array, len, doit) do{\
    int __loop;     \
    for (__loop = 0; __loop < len; __loop++) {  \
        doit(array[__loop]);   \
    }  \
}while(0)

static inline void print_val(int val)
{
    printf("%d\n", val);
}

void insert_sort(int array[], int size)
{
    int i,j;
    for (i = 1; i < size; i++) {
        for (j = i; j >0 && array[j] < array[j - 1]; j--) {
            SWAP(array[j], array[j - 1]);
        }
    }
}

void select_sort(int array[], int size)
{
	int i, j, minidx;
	for (i = 0; i < size; i++)
	{
		minidx = i; //set min index to head
        /*find least values smallest */
		for (j = i + 1; j < size; j++) {
			if (array[j] < array[minidx])
				minidx = j;
        }
		SWAP(array[i], array[minidx]); //swap this val to head
	}
}

static inline int quick_partion(int array[],int left,int right)
{
    /* select a random index in left <--> right as part point */
    int partidx = (rand() % (right - left + 1)) + left;

    /* record part val, and move left val to part position
     * now, left position can store value.
     */
    int part_val = array[partidx];
    array[partidx] = array[left];

    while (left < right) {
        /* from right search first val < part_val and move to left empty slot
         * and make right slot empty
         */
        while (left < right && array[right] >= part_val)
            right--;
        if (left < right) {
            array[left++] = array[right];
        }

        /* from left search first val >= part_val and move to right empty slot
         * and make right slot empty
         */
        while (left < right && array[left] < part_val) {
            left++;
        }
        if (left < right) {
            array[right--] = array[left];
        }
    }
    array[left] = part_val;
    return left;
}

static inline int partion(int array[],int left,int right)
{
    /* less or equal index and walk index for walking array */
    int le_idx ,walk;
    /* select a random index in left <--> right as partion point */
    int partidx = (rand() % (right - left + 1)) + left;

    /* judge edge condition */
    if(left >= right)
        return left;
    /* SWAP part_val to first position */
    SWAP(array[left], array[partidx]);

    /* idx less or equal than part_val now at left */
    le_idx = left;
    for (walk = le_idx + 1; walk <= right; walk++)  {
        /* array[left] is part_val */
        if(array[walk] < array[left])   {
            ++le_idx;
            /*IMPORTANT: use ++le_idx to make sure [left ... le_idx] <= part_val */
            SWAP(array[le_idx], array[walk]);
        }
    }
    SWAP(array[left], array[le_idx]);
    return le_idx;
}

void quick_sort(int array[],int begin,int end){
    if (begin < end){
        int partidx = partion(array, begin, end);
        quick_sort(array, begin, partidx - 1);
        quick_sort(array, partidx + 1, end);
    }
}

int main(int argc, const char *argv[])
{
    int a[] = {2,3,54,5,6,21,8,-1};
    quick_sort(a, 0, ARRAY_LEN(a)-1);
    ARRAY_WALK(a, ARRAY_LEN(a), print_val);
    return 0;
}
