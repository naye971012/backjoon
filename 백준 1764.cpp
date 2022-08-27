#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b); 

int main()
{
	int n,m;
	scanf("%d %d", &n,&m);
	char arr[n+m][20];

	for (int i = 0; i < (n+m) ; i++)
	{
		scanf("%s", arr[i]);
	}
	
	qsort( arr, n+m, sizeof(arr[0]), compare);
	int cnt=0;
	char ans[n+m][20];
	for(int i=1;i<n+m;i++){
		if(strcmp(arr[i],arr[i-1])==0){
			strcpy(ans[cnt++],arr[i]);
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%s\n",ans[i]);
	}
	
	return 0;
}

int compare(const void *a, const void *b) 
{ 
    return strcmp((char*)a, (char*)b);

}
