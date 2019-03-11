
#include <iostream>
#include <fstream> 
#include <cstdio>
#include <cwchar>
#include <clocale>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<wstring, int> DIC;
int DicMaxLength;

int FindInDic(wstring s){
	if( DIC.find(s)!=DIC.end() )return 1;
	else return 0;
}

#define DicPathName "dic.txt"
int InitDic(){
	
	//setlocale(LC_ALL,"Chs"); // ��������
	
	wifstream wifs; 
	wstring word;
	int cnt=0;
	
	DIC.clear();
	
	wifs.open(DicPathName);
	
	DicMaxLength=0;
	while( wifs >> word ){
		wcout << word << endl;
		if( DicMaxLength<word.length() )
			DicMaxLength=word.length();
		DIC.insert( make_pair(word, (++cnt)) );
	}
	wifs.close();
	
	//printf(L"�ɹ���%s�м���%d���ʻ�\n", DicPathName, cnt);
	//printf("�ɹ�����%d���ʻ�\n", cnt);
	//fwprintf("�ɹ�����%d���ʻ�\n", cnt);
	cout << "�ɹ�����" << cnt << "���ʻ�" << endl;
	
	return cnt;
}

// partition
void solve(wstring str){
	int pos, l, len=str.length(), remlen;
	vector<wstring> res;
	vector<wstring>::iterator it;
	
	res.clear();
	for(pos=0; pos<len; pos+=l){
		remlen=len-pos;
		if( remlen>DicMaxLength )
			remlen=DicMaxLength;
		for(l=remlen; l>1; l--)
			if( FindInDic(str.substr(pos, l)) )
				break;
		res.push_back(str.substr(pos, l));
	}
	
	for(it=res.begin(); it!=res.end(); it++)
		wcout << *it << " ";
}

int main(){
	
	setlocale(LC_ALL,"Chs"); // ��������
	
	//------------------
	wofstream wofs; 
	wstring word;
	int cnt=0;
	
	cin >> cnt;
	wofs.open(DicPathName);
	while(cnt--){
		wcin >> word;
		cout << "ok" << endl;
		wcout << L"w ok" << endl;
		wcout << word << endl;
		wofs << word << endl;
	}
	wofs.close();
	//------------------
	
	InitDic();
	
	//wcout << L"���ó�����";
	//solve(L"���ó�����"); 
	
	wstring s;
	wcin >> s;
	solve(s); 
	
	//string s="123456";
	//cout << s.substr(4, 5);
	
	return 0;
}





