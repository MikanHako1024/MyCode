
#include <stdio.h>
#include <math.h>

int N;

//int dp[5000500][5];
//int dfs(int a, int b)
	// ？？

//int ans[4];
//int dfs(int lmtL, int lmtR, int m, int rem)
//{
//	//printf("%d %d %d %d--", lmtL, lmtR, m, rem);
//	//printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
//	int t;
//	
//	//if( lmtR<lmtL )return 0; // ？ 
//	if( rem<0 )return 0;
//	
//	//if( m>=4 )
//	//{
//	//	if( rem==0 )return 1;
//	//	else return 0;
//	//}
//		// ？m==3时即可结束
//		// ？因之后若要使rem为0 选择是固定的 
//		// ？... 
//	if( m>=3 )
//	{
//		t=sqrt(rem);
//		ans[m]=t;
//		if( t*t==rem )return 1;
//		else return 0;
//	}
//	
//	while(1)
//	{
//		if( lmtR<lmtL )return 0;
//		ans[m]=lmtR;
//		t=rem-lmtR*lmtR;
//		//if( dfs(lmtR, (int)sqrt(t/4)+1, m+1, t)==1 )
//			// ？错了 
//			// ？开始时剩有4个数 故除以4
//			// ？之后剩下的数少了 不应再除以4
//			// ？... 
//		if( dfs(lmtR, (int)sqrt(t/(3-m)), m+1, t)==1 )
//				// ？观察到 lmtR最初总是 (int)sqrt(rem/(3-m+1)) 
//				// ？故可尝试省略 lmtR的传递 而是直接计算出来 
//			return 1;
//		lmtR--;
//		//if( lmtR<lmtL )return 0;
//			// ？？ 
//	}
//}
//	// ？a->b->c->d 之后的数要更大 同时要尽可能取大的 ...
//		// ？？想办法 改成 之后的数要更小 同时要尽可能取大的 ... 
//		// ？？这样更好处理 ... 
//	// ？d->c->b->a 之后的数要更小 同时要尽可能取大的 ...
//		// ？？都是要尽可能取大的 ...  
//			// ？？尽可能取小 ... 



// ？观察到 lmtR最初总是 (int)sqrt(rem/(3-m+1)) 
// ？故可尝试省略 lmtR的传递 而是直接计算出来 
// ？... 
int ans[4];
int dfs(int lmt, int m, int rem)
{
	int z;
	if( rem<0 )return 0;
	if( m>=3 )
	{
		ans[m]=(int)sqrt(rem);
		if( ans[m]*ans[m]==rem )return 1;
		else return 0;
	}
	
	z=(int)sqrt(rem/(4-m));
	while(1)
	{
		if( z<lmt )return 0;
		ans[m]=z;
		if( dfs(z, m+1, rem-z*z)==1 )
			return 1;
		z--;
	}
}

// ？
// ？存在子过程：4个数递增平方和N，1~3个数递增平方和rem 
// ？但相同状态可能结果不同 而且可能会出现不合条件的情况 应是dfs 
// ？...
 
void f(int n)
{
	int a, b, c, d, rem=n;
	
	for(a=0; a<=n; a++){
		if( rem-a*a<0 )break;
		rem-=a*a;
		for(b=a; b<n; b++){
			if( rem-b*b<0 )break;
			rem-=b*b;
			for(c=b; c<n; c++){
				if( rem-c*c<0 )break;
				rem-=c*c;
				if( rem<0 )break;
				for(d=c; d<n; d++){
					if( rem-d*d<0 )break;
					rem-=d*d;
					if( rem==0 ){
						printf("%d %d %d %d\n", a, b, c, d);
					}
					rem+=d*d;
				}
				rem+=c*c;
			}
			rem+=b*b;
		}
		rem+=a*a;
	}
}

int main()
{
	int z;
	scanf("%d", &N);
	
	//f(N);
	
	//dfs(0, (int)sqrt(N/4), 0, N);
	dfs(0, 0, N);
	
	for(z=0; z<4; z++)
	{
		if(z)printf(" ");
		printf("%d", ans[z]);
	}
	
	return 0;
}

