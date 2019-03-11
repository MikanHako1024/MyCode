
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



#include <vector>

#define NodeSize (100100)
typedef struct _Node{
	string name;
	//vector<struct _Node> list;
	vector<int> list;
}Node;
Node node[100100];
int top=0;

//class Node{
//	private:
//		string name;
//		vector<Node> list;
//		
//	public:
//		Node(string str=""){
//			name=str;
//		}
//		Node(Node &n){
//			name=n.name;
//			list=n.list;
//		}
//		~Node(){
//			list.clear();
//		}
//		
//		void AddItem(string str){
//			Node n(str);
//			list.push_back(n);
//		}
//		
//};


//Node root;


map<string, int> ReSearch;

//void AddItem(string str, int addid){
//	
//}

void DemoLoad(){
	/*	
	 *	0				1				2			
	 *	01		02		12		13		23		24	
	 *	012	013	023	024	123	124	134	135	234	235	245	246	
	 */
	
	int id[4]={0};
	string str;
	int addid, preid;
	
	top=0;
	node[id[0]].name="Start";
	
	str="0";
	node[id[1]=(++top)].name=str;
	ReSearch[str]=id[1];
	node[id[0]].list.push_back(id[1]);
	
	str="01";
	node[id[2]=(++top)].name=str;
	ReSearch[str]=id[2];
	node[id[1]].list.push_back(id[2]);
	
	str="012";
	node[id[3]=(++top)].name=str;
	ReSearch[str]=id[3];
	node[id[2]].list.push_back(id[3]);
	
	str="013";
	node[id[3]=(++top)].name=str;
	ReSearch[str]=id[3];
	node[id[2]].list.push_back(id[3]);
	
	str="02";
	node[id[2]=(++top)].name=str;
	ReSearch[str]=id[2];
	node[id[1]].list.push_back(id[2]);
	
	str="023";
	node[id[3]=(++top)].name=str;
	ReSearch[str]=id[3];
	node[id[2]].list.push_back(id[3]);
	
	str="024";
	node[id[3]=(++top)].name=str;
	ReSearch[str]=id[3];
	node[id[2]].list.push_back(id[3]);
	
}

void DemoPrint(){
	
	int id[4]={0};
	string str;
	int addid, preid;
	
	vector<int>::iterator it[3];
	
	
	for(int z=1; z<=top; z++)
		printf("%s\n", node[z].name.c_str());
	
	
	for(it[0]=node[id[0]].list.begin(); 
		it[0]!=node[id[0]].list.end(); it[0]++){
		
		id[1]=*(it[0]);
		for(it[1]=node[id[1]].list.begin(); 
			it[1]!=node[id[1]].list.end(); it[1]++){
			
			id[2]=*(it[1]);
			for(it[2]=node[id[2]].list.begin(); 
				it[2]!=node[id[2]].list.end(); it[2]++){
				
				id[3]=*(it[2]);
				
				cout << id[1] << ":";
				cout << id[2] << ":";
				cout << id[3] << "  ";
				
				cout << node[id[1]].name << "--";
				cout << node[id[2]].name << "--";
				cout << node[id[3]].name << endl;
			}
		}
	}
	
	
}



#include <cstdlib>

#define XXPathName "XX.dat"
int Load_XX(){
	FILE *fp=NULL;
	
	fp=fopen(XXPathName, "rb");
	if( fp==NULL ){
		printf("打开失败！\n");
		return 0;
	}	
	
	fread(node, sizeof(node), 1, fp);
	
	fclose(fp);
	
	return 1;
}

int Save_XX(){
	FILE *fp=NULL;
	
	fp=fopen(XXPathName, "wb");
	if( fp==NULL ){
		printf("打开失败！\n");
		return 0;
	}	
	
	fwrite(node, sizeof(node), 1, fp);
	
	fclose(fp);
	
	return 1;
}


int main(){
	
//	DemoLoad();
//	Save_XX();
//	DemoPrint();
	
	Load_XX();
	DemoPrint();
	
	
	return 0;
}


// ？ 输出后 以ANSI编码打开  


