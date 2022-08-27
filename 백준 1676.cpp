#include <stdio.h>
int main(){
	int n;
	int two=0;
	int five=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x=i;
		
		while(x%5==0){
		if(x%5==0){
		five++;
		x/=5;
		}
		}
	
	}
	int ans;
	ans=five;

	printf("%d",ans);
	return 0;
}
