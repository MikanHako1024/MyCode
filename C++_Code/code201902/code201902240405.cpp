
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


wchar_t Mysubstr_temp[256];
wchar_t *Mysubstr(wchar_t s[], int pos, int l){
	int i=0;
	while(l--)
		Mysubstr_temp[i++]=s[pos++];
	Mysubstr_temp[i]=L'\0';
	return Mysubstr_temp;
}

wchar_t *(DIC[1<<16]);
int dictop=0;
int DicMaxLength=0;

//    //wchar_t str[] = L"�������ֽ������";
//    wchar_t str[100];
//    setlocale(LC_ALL,"Chs");    //��������
//    wscanf(L"%ls", str);
//    wprintf(L"%ls\n%lc\n",str,str[1]);


int FindInDic(wchar_t s[]){
	int z;
	for(z=0; z<dictop; z++)
		if( wcscmp(s, DIC[z])==0 )
			return 1;
	return 0;
}


#define DicPathName "dic.txt"
#define StrMaxSize 256
int InitDic(){
	
	//setlocale(LC_ALL,"Chs"); // ��������
	
	FILE *fp=NULL;
	wchar_t word[StrMaxSize]; // read 
	int cnt=0;
	
	fp=fopen(DicPathName, "r");
	if( fp==NULL ){
		printf("��ʧ��\n");
		return -1;
	}
	
	dictop=0;
	DicMaxLength=0;
	//while( fwscanf(fp, L"%ls", word)!=EOF ){
//	while( !feof(fp) ){
//		fwscanf(fp, L"%ls", word);
//		wprintf(L"%ls\n", word);
//		if( DicMaxLength<wcslen(word) )
//			DicMaxLength=wcslen(word);
//		DIC[dictop]=(wchar_t *)malloc(sizeof(word));
//		wcscpy(DIC[dictop], word);
//		dictop++;
//		cnt++;
//	}
	// �������һ��  
//
//	fwscanf(fp, L"%ls", word);
//	while( !feof(fp) ){
//		wprintf(L"%ls\n", word);
//		if( DicMaxLength<wcslen(word) )
//			DicMaxLength=wcslen(word);
//		DIC[dictop]=(wchar_t *)malloc(sizeof(word));
//		wcscpy(DIC[dictop], word);
//		dictop++;
//		cnt++;
//		fwscanf(fp, L"%ls", word);
//	}
	while(1){
		fwscanf(fp, L"%ls", word);
		if( feof(fp) )break;
		
		wprintf(L"%ls\n", word);
		if( DicMaxLength<wcslen(word) )
			DicMaxLength=wcslen(word);
		DIC[dictop]=(wchar_t *)malloc(sizeof(word));
		wcscpy(DIC[dictop], word);
		dictop++;
		cnt++;
	}
	fclose(fp);
	
	//printf("�ɹ���%s�м���%d���ʻ�\n", DicPathName, cnt);
	//printf("�ɹ�����%d���ʻ�\n", cnt);
	wprintf(L"�ɹ�����%d���ʻ�\n", cnt);
	//cout << "�ɹ�����" << cnt << "���ʻ�" << endl;
	
	return cnt;
}

// partition
//void solve(wstring str){
//	int pos, l, len=str.length(), remlen;
//	vector<wstring> res;
//	vector<wstring>::iterator it;
//	
//	res.clear();
//	for(pos=0; pos<len; pos+=l){
//		remlen=len-pos;
//		if( remlen>DicMaxLength )
//			remlen=DicMaxLength;
//		for(l=remlen; l>1; l--)
//			if( FindInDic(str.substr(pos, l)) )
//				break;
//		res.push_back(str.substr(pos, l));
//	}
//	
//	for(it=res.begin(); it!=res.end(); it++)
//		wcout << *it << " ";
//}
void solve(wchar_t str[]){
	//int pos, l, len=str.length(), remlen;
	//vector<wstring> res;
	//vector<wstring>::iterator it;
	
	int pos, l, len=wcslen(str), remlen;
	
	//res.clear();
	for(pos=0; pos<len; pos+=l){
		remlen=len-pos;
		if( remlen>DicMaxLength )
			remlen=DicMaxLength;
		for(l=remlen; l>1; l--)
			//if( FindInDic(str.substr(pos, l)) )
			if( FindInDic(Mysubstr(str, pos, l)) )
				break;
		//res.push_back(str.substr(pos, l));
		
		wprintf(L"%ls ", Mysubstr(str, pos, l));
	}
	
	//for(it=res.begin(); it!=res.end(); it++)
		//wcout << *it << " ";
	putchar('\n');
}

int main(){
	
	setlocale(LC_ALL,"Chs"); // ��������
	
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
	
	solve(L"һ��������"); 
	
	//wcout << L"���ó�����";
	solve(L"���ó�����"); 
	
//	wstring s;
//	wcin >> s;
//	solve(s); 
	
	//string s="123456";
	//cout << s.substr(4, 5);
	
	return 0;
}





