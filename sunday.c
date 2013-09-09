#include <stdio.h>
#include <string.h>

inline int set_offset2tail(int *strpos, const char* str)
{
    int len = strlen(str);
    const char *pos_char = str + len;
    int pos = 1;
    while(--pos_char != str)
        if(strpos[*pos_char] == 0)
            strpos[*pos_char] = pos++;
    return len;
}

int sunday_search(const char *str1, const char *str2)
{
    int pos_in_str2[128]={0};
    int idx1 = 0;
    int idx2 = 0;
    int base_idx = 0;
    char nextchar;
    int len2 =set_offset2tail(pos_in_str2, str2);
    while(1) {
        for(idx1 = base_idx, idx2 = 0; (nextchar = str1[idx1]) != '\0'; idx1++, idx2++) {
            if(nextchar != str2[idx2])
                break;
        }
        if (str2[idx2] == '\0') {
            return base_idx;
        }
        if (nextchar == '\0') {
            return -1;
        }
        nextchar = str1[base_idx + len2];
        base_idx += (pos_in_str2[nextchar] == 0) ? len2 :pos_in_str2[nextchar];
    }
}


int main(int argc, const char *argv[])
{
    char str1[256];
    char str2[256];
    printf("input str1:\n");
    fgets(str1, sizeof(str1), stdin);
    *strchr(str1, '\n') = '\0';

    printf("input str2:\n");
    fgets(str2, sizeof(str2), stdin);
    *strchr(str2, '\n') = '\0';

    printf("str2 in str1 index is %d\n", sunday_search(str1, str2));
    return 0;
}
