
#include <stdio.h>
#include <math.h>

int N;

//int dp[5000500][5];
//int dfs(int a, int b)
	// ����

//int ans[4];
//int dfs(int lmtL, int lmtR, int m, int rem)
//{
//	//printf("%d %d %d %d--", lmtL, lmtR, m, rem);
//	//printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
//	int t;
//	
//	//if( lmtR<lmtL )return 0; // �� 
//	if( rem<0 )return 0;
//	
//	//if( m>=4 )
//	//{
//	//	if( rem==0 )return 1;
//	//	else return 0;
//	//}
//		// ��m==3ʱ���ɽ���
//		// ����֮����ҪʹremΪ0 ѡ���ǹ̶��� 
//		// ��... 
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
//			// ������ 
//			// ����ʼʱʣ��4���� �ʳ���4
//			// ��֮��ʣ�µ������� ��Ӧ�ٳ���4
//			// ��... 
//		if( dfs(lmtR, (int)sqrt(t/(3-m)), m+1, t)==1 )
//				// ���۲쵽 lmtR������� (int)sqrt(rem/(3-m+1)) 
//				// ���ʿɳ���ʡ�� lmtR�Ĵ��� ����ֱ�Ӽ������ 
//			return 1;
//		lmtR--;
//		//if( lmtR<lmtL )return 0;
//			// ���� 
//	}
//}
//	// ��a->b->c->d ֮�����Ҫ���� ͬʱҪ������ȡ��� ...
//		// ������취 �ĳ� ֮�����Ҫ��С ͬʱҪ������ȡ��� ... 
//		// �����������ô��� ... 
//	// ��d->c->b->a ֮�����Ҫ��С ͬʱҪ������ȡ��� ...
//		// ��������Ҫ������ȡ��� ...  
//			// ����������ȡС ... 



// ���۲쵽 lmtR������� (int)sqrt(rem/(3-m+1)) 
// ���ʿɳ���ʡ�� lmtR�Ĵ��� ����ֱ�Ӽ������ 
// ��... 
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

// ��
// �������ӹ��̣�4��������ƽ����N��1~3��������ƽ����rem 
// ������ͬ״̬���ܽ����ͬ ���ҿ��ܻ���ֲ������������ Ӧ��dfs 
// ��...
 
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

