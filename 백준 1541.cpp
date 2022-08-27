#include <stdio.h>
#include <string.h>
int main(){
	char map[51];
	scanf("%s",map);
	int n=strlen(map);
	
	int mul10=1;
	int cur;
	
	int save=0;
	int ans=0;
	
	for(int i=n-1;i>=0;i--){
		if(map[i]=='+'){
			mul10=1;
		}
		else if(map[i]=='-'){
			ans-=save;
			save=0;
			mul10=1;
		}
		else{

			cur=int(map[i])-48;
			save+=cur*mul10;
			mul10*=10;
			
		}
	//	printf("%d %d %d\n",mul10,save,ans);
	}
	ans+=save;
	printf("%d",ans);
	
	return 0;
}
