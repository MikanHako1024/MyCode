
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//struct _Node{
//	int x, y;
//	bool operator<(struct _Node n)     
//	{         
//		if( x!=n.x )return x<n.x;
//		else return y<n.y;
//	}
//};
//
//priority_queue<struct _Node> q;

struct _Node{
	int x, y;
	bool operator<(struct _Node n)     
	{         
		if( x!=n.x )return x<n.x;
		else return y<n.y;
	}
};

bool cmp(struct _Node a, struct _Node b)     
{
	if( a.x!=b.x )return a.x<b.x;
	else return a.y<b.y;
}
	
priority_queue<vector<struct _Node>, greater<struct _Node> > pq2;

int main(){
	int oper, x, y;
	struct _Node n;
	
	while(1){
		scanf("%d", &oper);
		
		if( oper==1 ){
			scanf("%d %d", &x, &y);
			//q.push(Node(x, y));
			n.x=x;
			n.y=y;
			q.push(n);
		}else if( oper==2 ){
			printf("out:%d %d\n", q.top().x, q.top().y);
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


