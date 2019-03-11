
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
//		printf("打开%s失败\n", DicPathName);
//		return -1;
//	}
	
	DicMaxLength=0;
	//while( fscanf(fp, "%s", word)!=EOF ){
	//while( (cin >> word)!=EOF ){ // ？错了 
	//while( wcin >> word ){ // ？？ 
	while( ifs >> word ){ // ？？ 
		if( DicMaxLength<word.length() )
			DicMaxLength=word.length();
		DIC.insert( make_pair(word, (++cnt)) );
	}
	fclose(fp);
	
	printf("成功从%s中加载%d个词汇\n", DicPathName, cnt);
	return cnt;
}

void solve(wstring str){
	int z, l;
	

	
}

int main(){
	//setlocale(LC_ALL,"Chs");	//设置中文
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
//	//solve("设置成中文"); 
//	wcin >> s;
//	solve(s); 
	
	
	
	return 0;
}






//int main(){
//	//setlocale(LC_ALL,"Chs");	//设置中文
//	//
//	//wchar_t str[100];
//	//wscanf(L"%ls", str);
//	//wprintf(L"%ls\n%lc\n\n",str,str[1]);
//	//printf("%d\n", sizeof(wchar_t));
//	
//	//string s;
//	//s="备案啥都会";
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
			System.out.println('开始初始化词典'); 
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
			System.out.println('完成初始化词典，词数目：'+cou nt); 
			System.out.println('最大分词长度：'+MAX_LENGTH); 
		}
		catch(IOException ex){ 
			System.err.println('词典装载失败:'+ex.getMessage()); 
		}
	}
	public static void main(String[] args){ 
		String text = '杨尚川是APDPlat应用级产品开发平台的作者'; 
		System.out.println(seg(text)); 
	}
	public static List seg(String text){ 
		List result = new ArrayList<>(); 
		while(text.length()>0){ 
		int len=MAX_LENGTH; 
		if(text.length() len=text.length(); 
	} //取指定的最大长度的文本去词典里面匹配 
	String tryWord = text.substring(0, 0+len); 
	while(!DIC.contains(tryWord)){ 
		//如果长度为一且在词典中未找到匹配，则按长度为一切分 
		if(tryWord.length()==1){ 
			break; 
		} 
		//如果匹配不到，则长度减一继续匹配 
		tryWord=tryWord.substring(0, tryWord.length()-1);
	}
	result.add(tryWord); 
	//从待分词文本中去除已经分词的文本 
	text=text.substring(tryWord.length()); 
} 
return result; 
} 
}
*/



