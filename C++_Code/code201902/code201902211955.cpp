
#include <iostream>
#include <fstream> 
#include <cstdio>
#include <cwchar>
#include <clocale>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, int> DIC;
int DicMaxLength;

int FindInDic(string s){
	if( DIC.find(s)!=DIC.end() )return 1;
	else return 0;
}

#define DicPathName "dic_.txt"
int InitDic(){
	
	ifstream ifs; 
	string word;
	int cnt=0;
	
	DIC.clear();
	
	ifs.open(DicPathName);
	
	DicMaxLength=0;
	while( ifs >> word ){
		if( DicMaxLength<word.length() )
			DicMaxLength=word.length();
		DIC.insert( make_pair(word, (++cnt)) );
	}
	ifs.close();
	
	printf("成功从%s中加载%d个词汇\n", DicPathName, cnt);
	return cnt;
}

// partition
void solve(string str){
	int pos, l, len=str.length(), remlen;
	vector<string> res;
	vector<string>::iterator it;
	
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
		cout << *it << " ";
}

int main(){
	
	setlocale(LC_ALL,"Chs");	//设置中文
	
	InitDic();
	
	
	solve("ABCDE"); 
	
	string s;
	cin >> s;
	solve(s); 
	
	//string s="123456";
	//cout << s.substr(4, 5);
	
	return 0;
}





