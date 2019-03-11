#include <stdio.h>

int L[13]={2, 1, 6, 8, 7}, nL=5;
int R[13]={5, 9, 7, 6, 2}, nR=5;
int nmax=5;

int dp[13][110][110];
	//  p  sum  mod 

// ？L[p]==R[p]的情况  
// ？L[-1],R[-1] (0)也可以视为相同 ...
 

//#define Sel3(a, b, c) ((e==0?a:(e==1?b:c)))
//for(t=Sel3(0, L[p]+1, R[p]); t<=Sel3(L[p], R[p]-1, 9); t++) 
									// ？先基础 再改进 ... 

int DP(int k)
{
	// long long int 
	int t, p, sum, mod, e, ret=0;
	int tL=L[0], tR=R[0], sumL=L[0], sumR=R[0], modL=L[0]%k, modR=R[0]%k;
	
//	for(p=0; p<nmax; p++)
//	{
//		tL=10*tL+L[p];
//		tR=10*tR+R[p];
//		for(e=0; e<3; e++)
//		{
//			for(t=Sel3(L[p]+1, 0, 0); t<=Sel3(9, 9, R[p]-1); t++) 
//												// ？先基础 再改进 ... 
//			{
//				for(sum=1; sum<=108-t; sum++)
//					for(mod=0; mod<k; mod++)
//							// ？先循环sum还是mod... 
//						dp[p][sum+t][(10*mod+t)%k]
//							+=dp[p-1][sum][mod];
//				
//				
//			}
//		}
//	}
		
			
		// 先从基础(原理/实质)开始 ... 
	for(p=1; p<nmax; p++)
	{
		for(t=0; t<=9; t++) 
			for(sum=1; sum<=108-t; sum++)
				for(mod=0; mod<k; mod++)
					dp[p][sum+t][(10*mod+t)%k]
						+=dp[p-1][sum][mod];
		for(t=L[p]+1; t<=9; t++) 
			dp[p][sumL+t][(modL+t)%k]++;
		tL=(10*tL)+L[p];
		sumL+=L[p];
		modL=(10*modL+L[p])%k;
		
		for(t=0; t<=R[p]-1; t++) 
			dp[p][sumR+t][(modR+t)%k]++;
		tR=(10*tR)+R[p];
		sumR+=R[p];
		modR=(10*modR+R[p])%k;
	}
	
	ret=dp[nmax-1][k][0];
	if( modL==0 )ret++;
	if( modR==0 )ret++;
	return ret;
}

/*

21687
59762

  2 - 21
    \ (L[p]+1 ~ 9) 
3-4 - 22-29-30-49-50-58
    / (0 ~ R[p]-1) 
  5 - 59

*/

// ？
// ？？不可 L-1 ~ R+1  
// ？...
 
void Input()
{
	int inL, inR, l, r, p;
	scanf("%d %d", &inL, &inR);
	
	l=inL; r=inR; nmax=0;
	while( l!=0 || r!=0 ){ l/=10; r/=10; nmax++; }
	
	l=inL; r=inR; 
	for(p=nmax-1; p>=0; p--)
	{
		L[p]=l%10; l/=10; 
		R[p]=r%10; r/=10; 
	}
}

int main()
{
	int a, b, c, n, ans=0;
	Input();
	
	for(n=1; n<=108; n++)
	{
		for(a=0; a<=12; a++)
			for(b=0; b<=108; b++)
				for(c=0; c<=108; c++)
					dp[a][b][c]=0;
		ans+=DP(n);
		//printf("%d\n", ans);
	}
	printf("%d", ans);
	
	return 0;
}

