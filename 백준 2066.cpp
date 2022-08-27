#include <stdio.h>
int search(int i,int map[101][101],int cur[101],int n){
	
//	printf("%d Å½»ö\n",i);
	
	for(int x=1;x<=n;x++){
		if(map[i][x]==1&&cur[x]==0){
			cur[x]=1;
			search(x,map,cur,n);
		}
	}
	return 0;
}
int main(){
	int cur[101]={0,};
	int n,m;
	scanf("%d",&n);
	int map[101][101]={0,};
	scanf("%d",&m);
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		map[x][y]=1;
		map[y][x]=1;
	}
	int cnt=0;
	
	for(int i=1;i<=n;i++){
		if(map[1][i]==1){
			cur[i]=1;
			search(i,map,cur,n);
		}
	}
	for(int i=1;i<=n;i++){
		if(cur[i]==1) cnt++;
	}
	printf("%d",cnt-1);
	return 0;
}
