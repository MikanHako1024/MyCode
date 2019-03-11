
// Q Q+P Q+2P Q+3P ... Q+(n-1)P 
// Q Q+P1 Q+P1+P2 Q+P1+P2+P3 ... Q+P1+P2+P3+...+P[n-1] 
// Pi=a or Pi=-b 
// sum = nQ+(n*(n-1)/2)*P
// (n*(n-1)/2)*P : (n-1)P1+(n-2)P2+...+1P[n-1]

// ？
// ？猜想 : x*a+y*(-b) 的 数对(x,y)对确定 P1,P2,...,P[n-1] 
		// ？错了 ...  
			// ？如 2a+3a-4b-5b = -2b-3b-4b+5a = ...  
	// ？有些时候可以进行一些猜想 ... 
// ？... 

// ？
// ？x*a+y*(-b) 必有 x+y=n*(n-1)/2 
// ？于是 nQ+x*a+y*(-b) = nQ+x*a+(n*(n-1)/2-x)*(-b) 
// ？= nQ+x*a+x*b-(n*(n-1)/2)*b = x*(a+b)-(n*(n-1)/2)*b+nQ 
// ？其中 (n*(n-1)/2)*b 是一个定值(对于一个case)  
// ？其中 Q 是 任意值(对于每一个case,x)  
// ？... 
 
// ？
// ？2a+3a-4b-5b = -2b-3b-4b+5a = ...  
// ？对应相同的 x=5 y=9 
	// ？分布 x,y 的?位置 ... 
// ？... 
 
// ？
// ？x*(a+b)-(n*(n-1)/2)*b+nQ = s 
// ？x*A+n*B+C=D, 变量A, B任意, 定值C,D 
// ？=> x*A+C-D=n*B => (x*A+C-D)/n=B => (x*A+C-D)|n
// ？一个x 可能对应多个组合 
// ？(0<=x<=n<=1000) 
// ？... 

// ？x=1 : 1 
// ？x=2 : 2 
// ？x=3 : 1,2 3
// ？x=4 : 1,3 4 
// ？x=5 : 1,4 2,3 5
// ？x=6 : 1,5 1,2,3 2,4 6
	// ？1,(5) : 1,(5 1,4 2,3) : 1,5 1,2,3 
// ？x=7 : (1),(6) (2),(5) (3),(4) 7 
	// : 1,6 1,2,4 2,5 2,1,4(X) 3,4 7 
// ？x=8 : (1),(7) (2),(6) (3),(5) 8
	// : 1,7 1,2,5 1,3,4 2,6 3,5 8 
		// ？递归 之前x的结果 
			// ？不过需要检查是否有重复的数字 

				//       ↑ 
				// ？原理实质 为何可以如此变化 
					// ？分解了 ff(x)  
				//       ↓ 

// ？f(sum, limit) 
// ？x=9 : f(9,1)
// ？f(9,1) : f(8,2)(选1) + f(9,2)(不选1) 
		// ？递归 [sum][limit] (？？0<=sum<=1000, 1<=limit<=1000)
			// ？避免了有重复的数字 



/*
?f(0,l) ?f(s,0)

f(0,1)=1 f(0,2)=1 f(0,3)=1 f(0,4)=1 f(0,5)=1 f(0,6)=1 
f(1,1)=1 f(1,2)=0 f(1,3)=0 f(1,4)=0 f(1,5)=0 f(1,6)=0 
f(2,1)=1 f(2,2)=1 f(2,3)=0 f(2,4)=0 f(2,5)=0 f(2,6)=0 
f(3,1)=2 f(3,2)=1 f(3,3)=1 f(3,4)=0 f(3,5)=0 f(3,6)=0 
f(4,1)=2 f(4,2)=1 f(4,3)=1 f(4,4)=1 f(4,5)=0 f(4,6)=0 
f(5,1)=3 f(5,2)=2 f(5,3)=1 f(5,4)=1 f(5,5)=1 f(5,6)=0 

f(5,1) = f(5,2) + f(4,2) 
         f(5,2) = f(5,3) + f(3,3) 
                  f(5,3) = f(5,4) + f(2,4) 
                           f(5,4) = f(5,5) + f(1,5)
                                    f(5,5) = f(5,6) + f(0,6) 
                                             f(5,6) = 0 
 => f(5,1) = f(4,2) + f(3,3) + f(2,4) + f(1,5) + f(0,6) 
solve(p)
= f(p,1) = f(p-1,2) + f(p-2,3) + ... + f(1,p) + f(0,p+1) 
= f(p,1) = f(p-1,2) + f(p-2,3) + ... + f(1,p) + 1 
                                        (？？+1的前提是p>=1 ...)
                                        (？？+1的1可看做是f(0,c)=1) 
	// ？
	// ？为何 原理实质 
	// ？...

同样地 f(5,2) = f(3,3) + f(2,4) + f(1,5) + f(0,6) 
于是知 f(p,q) = f(p-1,q+1) + f(p-2,q+2) + ... + f(1,q+p-1) + 1 
                                        (？？+1的前提是p>=q ...)
                                        (？？+1的1可看做是f(0,q+p)=1) 
f(p,q) = f(p,q+1) + f(p-q,q+1) 
         f(p,q+1) = f(p,q+2) + f(p-q-1,q+2) 
                    f(p,q+2) = f(p,q+3) + f(p-q-2,q+3) 
                                  ...
f(p,q) = f(p-q,q+1) + f(p-q-1,q+2) + ... + f(1,q) +


于是 f(5,1) = ( f(4,2) + f(3,3) + f(2,4) + f(1,5) + f(0,6) )
            =      2 * ( f(3,3) + f(2,4) + f(1,5) + f(0,6) )
            =               4 * ( f(2,4) + f(1,5) + f(0,6) )
            =                        8 * ( f(1,5) + f(0,6) )
            =                                16 * ( f(0,6) )
            =                                         16 
            	// ？错了 
				// ？f(4,2) 不等于 f(3,3) + f(2,4) + f(1,5) + f(0,6) 
				// ？f(4,2)  等于  f(2,3) + f(1,4) + f(0,5) 

于是 f(5,1) = f(4,2) + f(3,3) + f(2,4) + f(1,5) + f(0,6) 
            =   f(2,3) + f(1,4) + f(0,5) 
              + f(1,4) .... 

// ？
// ？发现 f(i,j)+f(i-1,j+1)+f(i-2,j+2)+...+f(0,j+i) 
// ？总能和 一个f(p,q) 相互表示 
// ？f(i,j)+f(i-1,j+1)+f(i-2,j+2)+...+f(0,j+i) = f(i+j-1,j-1)
// ？根据 f(i+j-1,j-1)=f(i+j-1-(j-1),j-1+1)+f(i+j-1,j-1+1) (选与不选) 
// ？  即 f(i+j-1,j-1)=f(i,j)+f(i+j-1,j) 易证 
// ？... 

// ？
// ？因 f(i,j)+f(i-1,j+1)+...+f(0,j+i) 能和 f(i+j-1,j-1) 相互表示 
// ？所以 arr[s][l] 可以用 arr2[][] 代替 
// ？... 


f(s,l)
	  l	
      1 2 3 4 5 6 7 8 9 10
    ----------------------- 
s 0 | 1 1 1 1 1 1 1 1 1 1 
  1 | 1 0 0 0 0 0 0 0 0 0  
  2 | 1 1 0 0 0 0 0 0 0 0  
  3 | 2 1 1 0 0 0 0 0 0 0  
  4 | 2 1 1 1 0 0 0 0 0 0  
  5 | 3 2 1 1 1 0 0 0 0 0  
  6 |           1 0 0 0 0  
  7 |             1 0 0 0  
  8 |               1 0 0  
  9 |                 1 0  

*/




#include <cstdio>
#include <iostream>
using namespace std;

long long int N, S, a, b, M;
//long long int dp[1010][1010];
//long long int dp[500500][1010];
long long int (*dp)[1010];
	// ？？M=[(N*(N-1)/2][N] (1+2+...+N) :最大可能的 s(即x) ...  

long long int f(long long int s, long long int l) // sum, limit (限制使用范围为[limit,N]) 
{
	if( s==0 )return 1;
	if( s<0 )return 0;
	if( s<l )return 0;
	if( l>N )return 0; // ？？... 
	if( dp[s][l]!=-1 )return dp[s][l];
	return dp[s][l]=f(s-l, l+1)+f(s, l+1);
}

int main()
{
	long long int i, j, x, ans=0, mod=100000007;
	scanf("%lld %lld %lld %lld", &N, &S, &a, &b);
	M=N*(N-1)/2;
	dp=new long long int[M][1010];
	
	//for(i=0; i<=N; i++)
	//	for(j=1; j<=N; j++)
	//		dp[i][j]=-1;
	//for(j=1; j<=N; j++)
	//	dp[0][j]=1;
		// ？
		// 兼容合并 
		// ？...
	for(i=0; i<=M; i++)
		for(j=1; j<=N; j++)
			dp[i][j]=(i==0?1:-1);
	
	// ？直接暴力 : 遍历x 判断可行  
	for(x=0; x<=M; x++)
		//if( (x*(a+b)-(N*(N-1)/2)*b-S)%N==0 )
		if( (x*(a+b)-M*b-S)%N==0 )
		//{
		//	printf("x=%d\nf(x, 1)=%d\n", x, f(x, 1));
			ans=(ans+f(x, 1))%mod;
		//}
	printf("%lld", ans);
	
	printf("\n");
	for(i=0; i<=M; i++)
	{
		for(j=1; j<=N; j++)
			printf("%3d ", dp[i][j]);
		printf("\n");
	}
//	
//	printf("\n");
//	for(i=0; i<=M; i++)
//	{
//		for(j=1; j<=N; j++)
//			printf("%3d ", f(i, j));
//		printf("\n");
//	}
	
	delete []dp;
	
	return 0;
}


// submit : 
/*
#include <stdio.h>

long long int N, S, a, b;
long long int dp[1010][1010];

long long int f(long long int s, long long int l) 
{
	if( s==0 )return 1;
	if( s<0 )return 0;
	if( s<l )return 0;
	if( l>N )return 0; 
	if( dp[s][l]!=-1 )return dp[s][l];
	return dp[s][l]=f(s-l, l+1)+f(s, l+1);
}

int main()
{
	long long int i, j, x, ans=0, mod=100000007;
	scanf("%lld %lld %lld %lld", &N, &S, &a, &b);
	
	for(i=0; i<=N; i++)
		for(j=1; j<=N; j++)
			dp[i][j]=(i==0?1:-1);
	
	for(x=0; x<=N; x++)
		if( (x*(a+b)-(N*(N-1)/2)*b-S)%N==0 )
			ans=(ans+f(x, 1))%mod;
	printf("%lld", ans);
	
	return 0;
}

*/

