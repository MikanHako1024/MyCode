
/*
��ʹ��MingGW��gcc4.7������C++����ʱ�����ֱ�����󡰴���converting to execution character set��Illegal byte sequence����

ԭ�����ҵĴ�����ʹ�� <wstring>��g++��Ҫ�����ѡ��ָ�������ļ��ı����ʽ��

ʹ��g++ test.cpp -finput-charset=GBK����GB2312������ͨ�����롣


�ַ�����������������ͷ�۵����⡣
*/

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(){
	
	//setlocale(LC_ALL, "zh_CN.UTF-8");
	//setlocale(LC_ALL, "zh_CN.Unicode");
	setlocale(LC_ALL, "");
	//setlocale(LC_ALL, "Chs");
	
	wchar_t s[] = L"��ã�����"; 
    wprintf(L"%ls\n", s); 
	
	
	return 0;
}





