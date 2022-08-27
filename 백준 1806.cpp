#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	long long int n,m;
	cin >> n >>m;
	int map[n]={0,};
	int fir=0;
	int sec=0;
	int len=100001;
	long long int cur=0;
	
	for(int i=0;i<n;i++){
		cin >> map[i];
	}
	cur+=map[0];
	while(fir<=sec && sec<n){
		if(cur>=m){
			len=min(len,sec-fir+1);
			cur-=map[fir++];
		}
		else{
			cur+=map[++sec];
		}
		printf("%d %d %d %d\n",fir,sec,cur,len);
	}
	if(len==100001) cout << 0;
	else cout << len;
	
	return 0;
}
