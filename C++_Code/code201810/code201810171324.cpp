
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node
{
	int val, len;
	//Node(int a=0, int b=0)
	//{ val=a; len=b; }
	bool operator<(struct Node &n)
	{ return val<n.val; }
}node[5050];

int delval=0, dellen=0, flag;

int main()
{
	int N, z, i, t, s=0, ans=0, index[5050];
	    
	scanf("%d", &N);
	for(z=0; z<N; z++)
	{
	    scanf("%d", &t);
	    s+=t-100;
	    node[z].val=s;
	    node[z].len=z+1;
	}
	sort(node, node+N);
	
	flag=N-1;
	
	for(z=0; z<N; z++)
	    index[node[z].len-1]=z;
	
	for(z=0; z<N; z++)
	{
		for(i=flag; i>=0; i--)
		    if( node[i].val-delval>0 )
		    {
		        if( ans<node[i].len-dellen )
		            ans=node[i].len-dellen;
		    }
		    else break;
		
		//delval=node[i].val;
		delval=node[index[z]].val;
		//dellen--;
		dellen++;
		flag=i;
	}

	printf("%d", ans);
	
	return 0;
}

