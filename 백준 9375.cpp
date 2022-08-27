#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void a, const void b)
{
	return strcmp(a, b);
}

int main(){
	int n,m;
	char dummy[100];
	char data[30][100];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%s %s",dummy,data[j]);
		}
		
		qsort(data,m,sizeof(char)*20,compare);
		int cnt=0;
		int x=0;
		int save[m]={1,};
		for(int j=1;j<m;j++){
			if(data[j]==data[j-1]) cnt++;
			else {
			save[x++]=cnt+1;
			cnt=0;
			}
		}
		int ans=1;
		for(int j=0;j<m;j++){
			printf("%s ",data[j]);
		}
		for(int j=0;j<x;j++){
			ans*=save[j];
		}
		printf("%d\n",ans-1);
	}
	

	
	return 0;
}
