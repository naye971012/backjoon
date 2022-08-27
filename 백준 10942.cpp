#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n,m,s,e;
	scanf("%d",&n);
	int map[2001]={0,};
	int dp[4001]={0,};
	for(int i=1;i<=n;i++){
		scanf("%d",&map[i]);
	}
	scanf("%d",&m);
	
	int x=0;
	for(int mid=1;mid<=n;mid++){
		x=0;
		while(mid-x>=1&&mid+x<=n){
			if(map[mid-x]!=map[mid+x]) break;
			x++;
			dp[mid]++;
		}
	} //È¦¼ö 
	int save;
	for(int mid=1;mid<n;mid++){
		save=mid+1;
		x=0;
		while(mid-x>=1 && save+x<=n){
			if(map[mid-x]!=map[save+x]) break;
			x++;
			dp[mid+2000]++;
		}
	}
	
	
	int mid;
	int size;
	for(int i=0;i<m;i++){
		scanf("%d %d",&s,&e);
		mid=(e+s)/2;
		size=e-s;
		
		if(size%2==0){
			if(dp[mid]>mid-s) printf("1\n");
			else printf("0\n");
		}
		else{
			if(dp[mid+2000]>mid-s) printf("1\n");
			else printf("0\n");
		}
	}
	
//	for(int i=1;i<=n;i++) cout << dp[i] << " ";
//	cout << endl;
//	for(int i=2001;i<=n+2000;i++) cout << dp[i] << " ";
	
	return 0;
}
