#include <stdio.h>
int main(){
	
	long long int dp[101]={0,};
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	dp[6]=3;
	for(int i=6;i<101;i++){
		dp[i]=dp[i-5]+dp[i-1];
	}
	int n;
	int x;
	long long int map[n];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	scanf("%d",&x);
	map[i]=dp[x];
	}
	for(int i=0;i<n;i++) printf("%lld\n",map[i]);
	return 0;
}
