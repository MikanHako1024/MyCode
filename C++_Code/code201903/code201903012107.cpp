
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <wchar.h>
//#include <locale.h>

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

map<wstring, int> DIC;
int DicMaxLength=0;

int FindInDic(wstring ws){
	return DIC.count(ws);
}


#define DicPathName "dic - ANSI.txt"
int InitDic(){
	//wifstream wifs;
	//wstring word;
	ifstream ifs;
	string word;
	wstring wsword;
	int cnt=0;
	
	//wifs.open(DicPathName);
	ifs.open(DicPathName);
	
//	if( ... ){
//		printf("打开失败\n");
//		return -1;
//	}
	
	
	DIC.clear();
	DicMaxLength=0;
	while(1){
		//wifs >> word;
		//if( wifs.eof() )break;
		ifs >> word;
		if( ifs.eof() )break;
			// ???
		
		wsword=string2wstring(word);
		
		if( cnt%100==0 )
			printf("%d\n", cnt);
		
		cout << word << endl;
		//wprintf(L"%ls\n", &word[0]); // ？可行 ... 
		//if( DicMaxLength<word.length() )
		//	DicMaxLength=word.length();
		if( DicMaxLength<wsword.length() )
			DicMaxLength=wsword.length();
		cnt++;
		DIC[wsword]=cnt;
	}
	//wifs.close();
	ifs.close();
	
	cout << "成功加载" << cnt << "个词汇" << endl;
	
	printf("DicMaxLength=%d\n", DicMaxLength);
	return cnt;
}

// partition
void solve(wstring wstr){
	int pos, l, len=wstr.length(), remlen;
	
	for(pos=0; pos<len; pos+=l){
		remlen=len-pos;
		if( remlen>DicMaxLength )
			remlen=DicMaxLength;
		for(l=remlen; l>1; l--)
		//for(l=remlen; l>2; l-=2) // 全中文情况 
			if( FindInDic(wstr.substr(pos, l))==1 )
				break;
		
		//wcout << wstr.substr(pos, l) << " ";
		cout << wstring2string(wstr.substr(pos, l)) << " ";
		
		//printf("%d ", wstr[pos]);
		//printf("%d ", wstr[pos+1]);
	}
	
	putchar('\n');
}

int main(){
	
	//setlocale(LC_ALL,"Chs"); // 设置中文
	
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
	
	
	InitDic();
	
	//solve("一二三四五"); 
	//solve("设置成中文"); 
	
	string inp;
	while(1){
		cin >> inp;
		wcout << string2wstring(inp) << endl;
		solve(string2wstring(inp));
		printf("%d\n", DIC.count(string2wstring(inp)));
	}
	
	return 0;
}

// 自动设置 



