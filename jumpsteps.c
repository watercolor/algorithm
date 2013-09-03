//ȫ���еĵݹ�ʵ��
#include <stdio.h>
#include <string.h>
/*һ������̨�׿���һ����1����2��������3�������������n���̨�ף��ܹ��м����߷�����ӡ���߷�*/
/* �����Ҳ����򵥵Ľⷨ */

static int eachsteps[] = {1,2,3};   /*store what step we can choose */
static int step_type_no = sizeof(eachsteps) / sizeof(eachsteps[0]); /* store choose number */

int jump_steps(int stepnum) {
    static int walkstep[100];       /* store walk choice*/
    static int walkstep_idx = 0;    /* store walk step */
    int i;
    int walk_no = 0;
    if(stepnum == 0) {
        /* print step choice */
        for (i = 0; walkstep[i] != 0; i++)
            printf("%d ", walkstep[i]);
        printf("\n");

        return 1;
    }
    for (i = 0; i < step_type_no; i++) {
        walkstep[walkstep_idx++] = eachsteps[i];  /* remember this step choice in walkstep */
        if(stepnum - eachsteps[i] >= 0)
            walk_no += jump_steps(stepnum - eachsteps[i]);
        walkstep[walkstep_idx--] = 0;             /* pop element */
    }
    return walk_no;
}

int test_jump_steps(int argc, const char *argv[])
{
    printf("number is %d", jump_steps(5));
    return 0;
}
