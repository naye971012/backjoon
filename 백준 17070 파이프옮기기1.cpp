#include <stdio.h>
int map[16][16]={0,};
int ans=0;
void move(int x,int y,int n, int m);

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	move(0,1,n,1);
	printf("%d",ans);
	
	return 0;
}

void move(int x,int y,int n, int m){
	if(m==1)	{ //가로 
	if(map[x][y+1]==0&&y+1<n)
	move(x,y+1,n,1);
	if(map[x+1][y]+map[x+1][y+1]+map[x][y+1]==0&&x+1<n&&y+1<n)
	move(x+1,y+1,n,3);
	if(x==n-1&&y==n-1)
	ans+=1;
}
	if(m==2)	{ //세로 
	if(map[x+1][y]==0&&x+1<n)
	move(x+1,y,n,2);
	if(map[x+1][y]+map[x+1][y+1]+map[x][y+1]==0&&x+1<n&&y+1<n)
	move(x+1,y+1,n,3);
	if(x==n-1&&y==n-1)
	ans+=1;
}
	if(m==3)	{ //대각 
	if(map[x][y+1]==0&&y+1<n)
	move(x,y+1,n,1);
	if(map[x+1][y]==0&&x+1<n)
	move(x+1,y,n,2);
	if(map[x+1][y]+map[x+1][y+1]+map[x][y+1]==0&&x+1<n&&y+1<n)
	move(x+1,y+1,n,3);
	if(x==n-1&&y==n-1)
	ans+=1;
}
}

