
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <clocale>

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;


// ========================================
// ========================================

#include <windows.h>
//将string转换成wstring  
wstring string2wstring(string str)  
{  
    wstring result;  
    //获取缓冲区大小，并申请空间，缓冲区大小按字符计算  
    int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);  
    //TCHAR* buffer = new TCHAR[len + 1];  
    wchar_t* buffer = new wchar_t[len + 1];  
    //多字节编码转换成宽字节编码  
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);  
    buffer[len] = '\0';             //添加字符串结尾  
    //删除缓冲区并返回值  
    result.append(buffer);  
    delete[] buffer;  
    return result;  
}  
  
//将wstring转换成string  
string wstring2string(wstring wstr)  
{  
    string result;  
    //获取缓冲区大小，并申请空间，缓冲区大小事按字节计算的  
    int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);  
    char* buffer = new char[len + 1];  
    //宽字节编码转换成多字节编码  
    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);  
    buffer[len] = '\0';  
    //删除缓冲区并返回值  
    result.append(buffer);  
    delete[] buffer;  
    return result;  
}
// ========================================
// ========================================

int main(){
	
	//setlocale(LC_ALL,"Chs"); // 设置中文
	//locale loc = locale::global( locale("chs",locale::ctype) );
	
    //system("chcp 65001");
    //system("chcp 936");
	
	
	//------------------
//	wofstream wofs; 
//	wstring word;
//	int cnt=0;
//	
//	cin >> cnt;
//	wofs.open(DicPathName);
//	while(cnt--){
//		wcin >> word;
//		cout << "ok" << endl;
//		wcout << L"w ok" << endl;
//		wcout << word << endl;
//		wofs << word << endl;
//	}
//	wofs.close();
	//------------------
	
	string str="一二三";
	wstring wstr=string2wstring(str);
	string str2=wstring2string(wstr);
	 
//	cout << "A:" << str << endl; 
//	cout << endl;
//	wcout << L"B:" << wstr << endl;
//	cout << endl;
//	cout << "C:" << str2 << endl;
//	cout << endl;
	
	printf("%s\n", &str[0]);
	wprintf(L"%ls\n", &wstr[0]);
	printf("%s\n", &str2[0]);
	
	
	
	return 0;
}

// 自动设置 



