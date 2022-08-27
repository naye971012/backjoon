#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int ans[n];
	int max=0;
	for(int i=0;i<n;i++){
		scanf("%d",&ans[i]);
		max > ans[i] ? 1 : max=ans[i];
	}

	int map[max+1]={0,};
	map[1]=1; //1
	map[2]=2; //1+1 , 2
	map[3]=4; //3 , 1+2 , 1+1+1 . 2+1
	map[4]=7; //
	int x=5;
		
	while(x<=max){	
		map[x]=map[x-1]+map[x-2]+map[x-3];
		x++;
	}
	for(int i=0;i<n;i++)
		{
		printf("%d\n",map[ans[i]]);
		}
	return 0;
}
	

	
