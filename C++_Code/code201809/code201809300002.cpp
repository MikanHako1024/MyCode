
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

struct _Node
{
	int R, C, flag;
	bool operator<(struct _Node &n)
	{ return R<n.R; }
}lie[200200];
int top_lie=0;
int flag_lie[100100];

struct _Node2
{
	int CL, CR;
	_Node2(int a, int b){ CL=a; CR=b; }
};
vector<struct _Node2> hang[100100];
int top_hang[100100];


void solve()
{
	int n, z=0, i, j, flag[2][100100], e=0;
	
	for(i=0; i<M; i++)
		flag[1-e][i]=0;
	
	for(n=1; n<=N; n++)
	{
		while( z<top_lie && lie[z].R<n )
		{
			if( lie[z].flag==0 )
				flag_lie[lie[z].C]=1;
			else // lie[z].flag==1
				flag_lie[lie[z].C]=0;
			z++;
		}
		
		for(i=0; i<M; i++)
			flag[e][i]=0;
		
	}
	
}

int main()
{
	int K, r1, c1, r2, c2;
	int z;
	
	scanf("%d %d %d", &N, &M, &K);
	for(z=0; z<K; z++)
	{
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		if( r1==r2 )
		{
			hang[r1].push_back(_Node2(c1, c2));
			top_hang[r1]++;
		}
		else // c1==c2
		{
			lie[top_lie].R=r1;
			lie[top_lie].C=c1;
			lie[top_lie].flag=0; // ÆðÊ¼ 
			lie[top_lie+1].R=r2+1; // ...
			lie[top_lie+1].C=c2;
			lie[top_lie+1].flag=1; // ½áÎ² 
			top_lie+=2;
		}
	}
	sort(lie, lie+top_lie);
	
	solve();
	
	return 0;
}

