#include <stdio.h>
typedef struct list_node{
    int data;
    struct list_node *next;
}list_node;

/* revert a list and return head after revert */
list_node* list_revert(list_node *list)
{
    list_node *last = NULL;
    list_node *next;
    while (list) {
        next = list->next;
        list->next = last;
        last = list;
        list = next;
    }
    return last;
}

int main(int argc, const char *argv[])
{
    list_node a[] = {
        {1, &a[1]},
        {2, &a[2]},
        {3, &a[3]},
        {4, NULL}
    };
    list_node *list = list_revert(a);

    while (list) {
        printf("%d\n", list->data);
        list = list->next;
    }
    return 0;
}
