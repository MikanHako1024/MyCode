
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
 
int main()
{
    //wchar_t str[] = L"�������ֽ������";
    wchar_t str[100];
    setlocale(LC_ALL,"Chs");    //��������
    wscanf(L"%ls", str);
    wprintf(L"%ls\n%lc\n",str,str[1]);
    return 0;
}


