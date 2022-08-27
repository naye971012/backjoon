#include <stdio.h>
#include <iostream> 
#include <math.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	
	int root;
	int dp[n+1]={0,};
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	dp[4]=1;
	
	root=sqrt(n);
	int map[root+1]={0,};
	for(int i=root;i>=1;i--){
		map[i]=i*i;	
	}
	
	for(int i=5;i<=n;i++){
		int ans=4;
		int save=4;
		for(int j=1;j<=sqrt(i);j++){
			
			dp[i-map[j]] > dp[i-1] ? ans=dp[i-1]+1 : ans=dp[i-map[j]]+1;
			save > ans ? save=ans : save=save;
		} 
		dp[i]=save;
	}

	cout << dp[n] << "\n";
	return 0;

}
