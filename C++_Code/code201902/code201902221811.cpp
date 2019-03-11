
#include <iostream>
#include <fstream> 
#include <cstdio>
#include <cwchar>
#include <clocale>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main(){
	
	setlocale(LC_ALL,"Chs"); // 设置中文
	
	//wstingstream ss;
	//ss << "11";
	
	wstring s;
	wcin >> s;
	
	wofstream wofs("1.txt");
	wofs << s;
	
	//ofstream ofs("2.txt");
	//ofs << s;
	// 报错 
	
	return 0;
}





