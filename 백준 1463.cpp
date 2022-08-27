#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int dp[n+1]={0,};
	int cnt=0;
	
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	int m;
	for(int i=4;i<=n;i++){
		cnt=0;
		m=i;
			if(m%6==0){
				dp[m/3]>dp[m/2] ? m/=2 : m/=3;
			}
			else if(m%3==0){
				m/=3;
			}
			else if(m%2==0){
				m/=2;
			}
			else{
				m-=1;
			}
		cnt++;	
		cnt+=dp[m];
		
		cnt > dp[i-1]+1 ? dp[i]=dp[i-1]+1 : dp[i]=cnt;
		
	}
	printf("%d",dp[n]);
	return 0;
}
