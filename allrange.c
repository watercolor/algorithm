//ȫ���еĵݹ�ʵ��
#include <stdio.h>
#include <string.h>
void Swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
//k��ʾ��ǰѡȡ���ڼ�����,m��ʾ���ж�����.
void AllRange(char *pszStr, int k, int m)
{
    int i;
    if (k == m)
    {
	static int s_i = 1;
	printf("  ��%3d������\t%s\n", s_i++, pszStr);
    }
    else
    {
	for (i = k; i <= m; i++) //��i�����ֱ�������������ֽ������ܵõ��µ�����
	{
	    Swap(pszStr + k, pszStr + i);
	    AllRange(pszStr, k + 1, m);
	    Swap(pszStr + k, pszStr + i);
	}
    }
}
void Foo(char *pszStr)
{
    AllRange(pszStr, 0, strlen(pszStr) - 1);
}
int main()
{
    char szTextStr[] = "1234";
    printf("%s 's all sort list below:\n", szTextStr);
    Foo(szTextStr);
    return 0;
}
