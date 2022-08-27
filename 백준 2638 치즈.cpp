#include <stdio.h>
int map[100][100];
int go=1;
void search_out(int x,int y,int n,int m);
void re(int n,int m);
void search_cheese(int count,int n,int m);
void print(int n,int m);
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&map[i][j]);
		}
	}
	int ans=-1;

	while(go==1){
	search_out(0,0,n,m);
	search_cheese(0,n,m);
	re(n,m);
	ans++;
	}
	
	printf("%d",ans);
	return 0;
}

void print(int n,int m){
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
}

void search_out(int x,int y,int n,int m){
	if(map[x+1][y]==0&&(x+1)<n){
		map[x+1][y]=2;
		search_out(x+1,y,n,m);
	}
	if(map[x-1][y]==0&&(x-1)>=0){
		map[x-1][y]=2;
		search_out(x-1,y,n,m);
	}
	if(map[x][y+1]==0&&(y+1)<m){
		map[x][y+1]=2;
		search_out(x,y+1,n,m);
	}
	if(map[x][y-1]==0&&(y-1)>=0){
		map[x][y-1]=2;
		search_out(x,y-1,n,m);
	}
}
void re(int n,int m){
	int q=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==2){
				map[i][j]=0;
			}
			if(map[i][j]==3){
				map[i][j]=0;
				q++;
			}
			
		}
	}
	if(q==0){
		go=0;
	}
	else{
		go=1;
	}
} 
void search_cheese(int count,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			count=0;
			int x=i;
			int y=j;
			if(map[i][j]==1){
				if(map[x+1][y]==2&&(x+1)<n){
				count++;
				
				}
				if(map[x-1][y]==2&&(x-1)>=0){
				count++;
					
				}
				if(map[x][y+1]==2&&(y+1)<m){  //0은 내부공기 2는 외부공기 1은 치즈 3은 지워지는치 
				count++;
					
				}
				if(map[x][y-1]==2&&(y-1)>=0){
				count++;
					
				}
				if(count>=2){
					map[i][j]=3;
				}
			}
		}
	}
}
