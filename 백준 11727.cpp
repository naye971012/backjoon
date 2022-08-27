#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int dp[1001]={0,};
	dp[0]=0;
	dp[1]=1;
	dp[2]=3;
	dp[3]=5;
	for(int i=4;i<=1000;i++){
		dp[i]=(dp[i-1]+dp[i-2]*2)%10007;
	}
	printf("%d",dp[n]);
	return 0;
}
