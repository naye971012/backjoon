#include <stdio.h>

int main(){
	long long int n=10;
	long long int fibo[1000000000000000000];
	fibo[0]=0;
	fibo[1]=1;
	fibo[2]=1;
	for(long long int i=3;i<n;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	for(long long int i=0;i<n;i++){
		printf("%d\n",fibo[i]);
	}
}
