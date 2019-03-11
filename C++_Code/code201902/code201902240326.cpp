
/*
在使用MingGW（gcc4.7）编译C++代码时，出现编译错误“错误：converting to execution character set：Illegal byte sequence”。

原因是我的代码中使用 <wstring>，g++需要额外的选项指定输入文件的编码格式。

使用g++ test.cpp -finput-charset=GBK（或GB2312）即可通过编译。


字符编码问题真是令人头疼的问题。
*/

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(){
	
	//setlocale(LC_ALL, "zh_CN.UTF-8");
	//setlocale(LC_ALL, "zh_CN.Unicode");
	setlocale(LC_ALL, "");
	//setlocale(LC_ALL, "Chs");
	
	wchar_t s[] = L"你好，世界"; 
    wprintf(L"%ls\n", s); 
	
	
	return 0;
}





