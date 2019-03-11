
#include <iostream>
#include <cstdio>
#include <cwchar>
#include <clocale>
#include <string>
//#include <wstring>
#include <map>

using namespace std;

map<wstring, int> DIC;
int DicMaxLength;

#define DicPathName ("dic.txt")
int InitDic(){
	//FILE *fp=NULL;
	ifstream ifs; 
	
	//char word[
	wstring word;
	
	int cnt=0;
	
	DIC.clear();
	
	ifs.fopen(DicPathName, "r");
//	if( fp==NULL ){
//		printf("��%sʧ��\n", DicPathName);
//		return -1;
//	}
	
	DicMaxLength=0;
	//while( fscanf(fp, "%s", word)!=EOF ){
	//while( (cin >> word)!=EOF ){ // ������ 
	//while( wcin >> word ){ // ���� 
	while( ifs >> word ){ // ���� 
		if( DicMaxLength<word.length() )
			DicMaxLength=word.length();
		DIC.insert( make_pair(word, (++cnt)) );
	}
	fclose(fp);
	
	printf("�ɹ���%s�м���%d���ʻ�\n", DicPathName, cnt);
	return cnt;
}

void solve(wstring str){
	int z, l;
	

	
}

int main(){
	//setlocale(LC_ALL,"Chs");	//��������
	//
	//wchar_t str[100];
	//wscanf(L"%ls", str);
	//wprintf(L"%ls\n%lc\n\n",str,str[1]);
	//printf("%d\n", sizeof(wchar_t));
	
	wstring s;
//	wstring::iterator iter;
//	wcin >> s;
//	iter=s.begin();
//	wcout << s << endl; 
//	wcout << s[2] << endl;
//	wcout << *iter << endl;
//	wcout << s.substr(2, 1) << endl;
//	wcout << s.substr(0, 1) << endl;
	
	
	wstring a;
	wcin >> a;
	wcout << a << endl;
	wcout << a.substr(1, 3) << endl; 
	wcout << *(a.begin()) << endl; 
	
	solve(a); 
	
//	InitDic();
//	
//	//solve("���ó�����"); 
//	wcin >> s;
//	solve(s); 
	
	
	
	return 0;
}






//int main(){
//	//setlocale(LC_ALL,"Chs");	//��������
//	//
//	//wchar_t str[100];
//	//wscanf(L"%ls", str);
//	//wprintf(L"%ls\n%lc\n\n",str,str[1]);
//	//printf("%d\n", sizeof(wchar_t));
//	
//	//string s;
//	//s="����ɶ����";
//	//cout << s << endl; 
//	////cout << left(s, 2) << endl; 
//	//cout << s[2] << endl;
//	
//	
//	
//	return 0;
//}



/*
public class WordSeg{ 
	private static final List DIC = new ArrayList<>(); 
	private static final int MAX_LENGTH; 
	static{ 
		try{
			System.out.println('��ʼ��ʼ���ʵ�'); 
			int max=1; 
			int count=0; 
			List lines = Files.readAllLines(Paths.get('D:/dic.txt'), Charset.forName('utf-8')); 
			for(String line : lines){ 
				DIC.add(line); 
				count++; 
				if(line.length()>max){
					max=line.length(); 
				}
			} 
			MAX_LENGTH = max; 
			System.out.println('��ɳ�ʼ���ʵ䣬����Ŀ��'+cou nt); 
			System.out.println('���ִʳ��ȣ�'+MAX_LENGTH); 
		}
		catch(IOException ex){ 
			System.err.println('�ʵ�װ��ʧ��:'+ex.getMessage()); 
		}
	}
	public static void main(String[] args){ 
		String text = '���д���APDPlatӦ�ü���Ʒ����ƽ̨������'; 
		System.out.println(seg(text)); 
	}
	public static List seg(String text){ 
		List result = new ArrayList<>(); 
		while(text.length()>0){ 
		int len=MAX_LENGTH; 
		if(text.length() len=text.length(); 
	} //ȡָ������󳤶ȵ��ı�ȥ�ʵ�����ƥ�� 
	String tryWord = text.substring(0, 0+len); 
	while(!DIC.contains(tryWord)){ 
		//�������Ϊһ���ڴʵ���δ�ҵ�ƥ�䣬�򰴳���Ϊһ�з� 
		if(tryWord.length()==1){ 
			break; 
		} 
		//���ƥ�䲻�����򳤶ȼ�һ����ƥ�� 
		tryWord=tryWord.substring(0, tryWord.length()-1);
	}
	result.add(tryWord); 
	//�Ӵ��ִ��ı���ȥ���Ѿ��ִʵ��ı� 
	text=text.substring(tryWord.length()); 
} 
return result; 
} 
}
*/



