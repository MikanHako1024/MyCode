
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
	
	setlocale(LC_ALL,"Chs"); // ��������
	
	//wstingstream ss;
	//ss << "11";
	
	wstring s;
	wcin >> s;
	
	wofstream wofs("1.txt");
	wofs << s;
	
	//ofstream ofs("2.txt");
	//ofs << s;
	// ���� 
	
	return 0;
}





