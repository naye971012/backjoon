#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int map[1001][1001]={0,};
int check[1001]={0,};

int dfs(int start,int n ){
	if(check[start]==1) return 0;
	
	printf("%d ",start);
	
	check[start]=1;
	
	for(int i=1;i<n+1;i++){
		if(map[start][i]==1 && check[i]==0){
			dfs(i,n);
		}
	}

	return 0;
}

int bfs(int start,int n,queue<int> qu){

	check[start]=1;
	qu.push(start);
	printf("%d ",start);
	
	while(qu.empty()==false){
		int x=qu.front();
		qu.pop();
		
		for(int i=1;i<n+1;i++){
			if(map[x][i]==1 && check[i]==0){
				check[i]=1;
				qu.push(i);
				printf("%d ",i);
				}		
			}
		}
	return 0;
}

int main(){
	int n,m,start;
	queue<int> qu;

	scanf("%d %d %d",&n,&m,&start);
	
	int fir,sec;
	for(int i=0;i<m;i++){
		scanf("%d %d",&fir,&sec);
		map[fir][sec]=1;
		map[sec][fir]=1;
	}
	
	dfs(start,n);
	for(int i=0;i<=n;i++) check[i]=0;
	printf("\n");
	bfs(start,n,qu);
	
	return 0;
}
