
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




// ========================================
// ========================================
void AnsiToUnicode()
{
	// ansi to unicode
	char* szAnsi = "abcd1234你我他";
	//预转换，得到所需空间的大小
	int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), NULL, 0);
	//分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
	wchar_t* wszString = new wchar_t[wcsLen + 1];
	//转换
	::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), wszString, wcsLen);
	//最后加上'\0'
	wszString[wcsLen] = '\0';
	//unicode版的MessageBox API
	MessageBoxW(GetSafeHwnd(), wszString, wszString, MB_OK);
 
	//接下来写入文本
	//写文本文件，头2个字节0xfeff，低位0xff写在前
	CFile cFile;
	cFile.Open(_T("1.txt"), CFile::modeWrite | CFile::modeCreate);
	//文件开头
	cFile.SeekToBegin();
	cFile.Write("\xff\xfe", 2);
	//写入内容
	cFile.Write(wszString, wcsLen * sizeof(wchar_t));
	cFile.Flush();
	cFile.Close();
	delete[] wszString;
	wszString =NULL;
 
 
	//方法2
	//设置当前地域信息，不设置的话，使用这种方法，中文不会正确显示
	//需要#include<locale.h>
	setlocale(LC_CTYPE, "chs"); 
	wchar_t wcsStr[100];
	//注意下面是大写S，在unicode中，代表后面是ansi字符串
	//swprintf是sprintf的unicode版本
	//格式的前面要加大写L，代表是unicode
	swprintf(wcsStr, L"%S", szAnsi);
	::MessageBoxW(GetSafeHwnd(), wcsStr, wcsStr, MB_OK);
}
// ========================================
// ========================================




int main(){
	
	int z;
	
	setlocale(LC_ALL,"Chs"); // 设置中文
	//locale loc = locale::global( locale("chs",locale::ctype) );
	
    //system("chcp 65001");
    //system("chcp 936");
	
	
	string str="一二三";
	wstring wstr=string2wstring(str);
	string str2=wstring2string(wstr);
	
	
//	char *pstr=&str[0];
//	wchar_t *pwstr=&wstr[0];
//	char *pstr2=&str2[0];
//	
//	printf("%p\n", pstr);
//	printf("%p\n", pwstr);
//	printf("%p\n", pstr2);
	
	
	for(z=0; str[z]!='\0'; z++)
		printf("%d ", str[z]);
	printf("\n");
	
	for(z=0; wstr[z]!='\0'; z++)
		printf("%d ", wstr[z]);
	printf("\n");
	
	for(z=0; str2[z]!='\0'; z++)
		printf("%d ", str2[z]);
	printf("\n");
	
	
	
	wofstream wofs; 
	wofs.open("out.txt");
	
	wofs << wstr << endl;
		
	wofs.close();
	
	
	return 0;
}

// 自动设置 



