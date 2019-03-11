
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;

int main(){
	int oper, num;
	
	while(1){
		scanf("%d", &oper);
		
		if( oper==1 ){
			scanf("%d", &num);
			q.push(num);
		}else if( oper==2 ){
			printf("out:%d\n", q.top());
			q.pop();
		}else
			break;
		
	}
	
	return 0;
}

/*
1 15
1 65
1 100
1 35
2 
2 
1 1465
2 
1 200
1 20
2
2
2
2
*/


