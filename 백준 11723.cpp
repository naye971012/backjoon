#include <stdio.h>
#include <string.h>
//��Ʈ����ŷ 
char a[10];

int main(){
    int M,x;
    int s = 0;

    scanf("%d",&M);

    while(M--){
        scanf("%s",a);
        if(strcmp(a,"all")==0){
            s = (1<<20)-1;
            continue;
        }
        else if(strcmp(a,"empty")==0){
            s = 0;
            continue;
        }

        scanf("%d",&x);

        int k = 1<<(x-1);

        if(strcmp(a,"add")==0){
            s |= k;
        }
        else if(strcmp(a,"remove")==0){
            s &= ~k;
        }
        else if(strcmp(a,"check")==0){
            printf("%d\n",(s&k)>0);
        }
        else if(strcmp(a,"toggle")==0){
            s ^= k;
        }
    }

    return 0;
}
