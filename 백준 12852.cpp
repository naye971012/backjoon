#include <stdio.h>
#include <iostream>
using namespace std;

int compare_3(int a,int b,int c){
	int cur=0;
	if(a<=b && a<=c) cur=1;
	if(b<=a && b<=c) cur=2;
	if(c<=a && c<=b) cur=3;
	return cur;

}

int main(){
	int n;
	scanf("%d",&n);
		
	// +1 or x2 or x3

	int dp[1000001][2]={0,};
	dp[1][0]=0; 
	dp[2][0]=1; 
	dp[2][1]=1; // 2 1
	dp[3][0]=1; 
	dp[3][1]=1;// 3 1
	dp[4][0]=2; 
	dp[4][1]=2;// 4 2 1
	dp[5][0]=3; 
	dp[5][1]=4;// 5 4 2 1
	dp[6][0]=2; 
	dp[6][1]=2;// 6 2 1

	int m;
	int max;
	int cur;
	for(int i=7;i<=n;i++){
			m=i;
			
			
			max=dp[m-1][0];			
			
			if(m%6==0){
				cur=compare_3(max,dp[m/3][0],dp[m/2][0]);	
			}
			
			else if(m%3==0){
				max > dp[m/3][0] ? cur=2 : cur=1;
			}
			
			else if(m%2==0){
				max > dp[m/2][0] ? cur=3 : cur=1;
			}
			else
				cur=1;	
			
			switch(cur){
				case 1:
					dp[m][1]=m-1;
					dp[m][0]=dp[m-1][0]+1;
					break;
				case 2:
					dp[m][1]=m/3;
					dp[m][0]=dp[m/3][0]+1;
					break;
				case 3:
					dp[m][1]=m/2;
					dp[m][0]=dp[m/2][0]+1;
					break;
				default:
					break;
			}
	}

	
	cout << dp[n][0] << endl;
	cout << n << " ";
	while(n!=1){
		
		cout << dp[n][1] << " ";
		n=dp[n][1];
	}

	
	return 0;
}
