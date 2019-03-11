
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
 
int main()
{
    //wchar_t str[] = L"中文文字解决方案";
    wchar_t str[100];
    setlocale(LC_ALL,"Chs");    //设置中文
    wscanf(L"%ls", str);
    wprintf(L"%ls\n%lc\n",str,str[1]);
    return 0;
}


