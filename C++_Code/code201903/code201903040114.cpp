
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
//��stringת����wstring  
wstring string2wstring(string str)  
{  
    wstring result;  
    //��ȡ��������С��������ռ䣬��������С���ַ�����  
    int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);  
    //TCHAR* buffer = new TCHAR[len + 1];  
    wchar_t* buffer = new wchar_t[len + 1];  
    //���ֽڱ���ת���ɿ��ֽڱ���  
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);  
    buffer[len] = '\0';             //����ַ�����β  
    //ɾ��������������ֵ  
    result.append(buffer);  
    delete[] buffer;  
    return result;  
}  
  
//��wstringת����string  
string wstring2string(wstring wstr)  
{  
    string result;  
    //��ȡ��������С��������ռ䣬��������С�°��ֽڼ����  
    int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);  
    char* buffer = new char[len + 1];  
    //���ֽڱ���ת���ɶ��ֽڱ���  
    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);  
    buffer[len] = '\0';  
    //ɾ��������������ֵ  
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
	char* szAnsi = "abcd1234������";
	//Ԥת�����õ�����ռ�Ĵ�С
	int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), NULL, 0);
	//����ռ�Ҫ��'\0'�����ռ䣬MultiByteToWideChar�����'\0'�ռ�
	wchar_t* wszString = new wchar_t[wcsLen + 1];
	//ת��
	::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), wszString, wcsLen);
	//������'\0'
	wszString[wcsLen] = '\0';
	//unicode���MessageBox API
	MessageBoxW(GetSafeHwnd(), wszString, wszString, MB_OK);
 
	//������д���ı�
	//д�ı��ļ���ͷ2���ֽ�0xfeff����λ0xffд��ǰ
	CFile cFile;
	cFile.Open(_T("1.txt"), CFile::modeWrite | CFile::modeCreate);
	//�ļ���ͷ
	cFile.SeekToBegin();
	cFile.Write("\xff\xfe", 2);
	//д������
	cFile.Write(wszString, wcsLen * sizeof(wchar_t));
	cFile.Flush();
	cFile.Close();
	delete[] wszString;
	wszString =NULL;
 
 
	//����2
	//���õ�ǰ������Ϣ�������õĻ���ʹ�����ַ��������Ĳ�����ȷ��ʾ
	//��Ҫ#include<locale.h>
	setlocale(LC_CTYPE, "chs"); 
	wchar_t wcsStr[100];
	//ע�������Ǵ�дS����unicode�У����������ansi�ַ���
	//swprintf��sprintf��unicode�汾
	//��ʽ��ǰ��Ҫ�Ӵ�дL��������unicode
	swprintf(wcsStr, L"%S", szAnsi);
	::MessageBoxW(GetSafeHwnd(), wcsStr, wcsStr, MB_OK);
}
// ========================================
// ========================================




int main(){
	
	int z;
	
	setlocale(LC_ALL,"Chs"); // ��������
	//locale loc = locale::global( locale("chs",locale::ctype) );
	
    //system("chcp 65001");
    //system("chcp 936");
	
	
	string str="һ����";
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

// �Զ����� 



