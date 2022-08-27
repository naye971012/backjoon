#include <stdio.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int map[n+1]={0,};
	int fir,sec;
	
	for(int i=0;i<n;i++){
		scanf("%d",&map[i+1]);
		map[i+1]+=map[i];
	}
	int ans[m];
	for(int i=0;i<m;i++){
		scanf("%d %d",&fir,&sec);
		ans[i]=map[sec]-map[fir-1];
	}
	for(int i=0;i<m;i++){
		printf("%d\n",ans[i]);
	}
	
	
	return 0;
}
