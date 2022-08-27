#include <stdio.h>
#include <queue>

using namespace std;

int main() {
 int d[200001]={0};
 int n, m;
 scanf("%d %d",&n,&m);
 queue<int> q;
 q.push(n);
 d[n]=1;//?초기값?방문?여부를?위해?인위적으로?1?증가
while(!q.empty()){
	int now=q.front();
	q.pop();

	if(now-1>=0&&d[now-1]==0){
	d[now-1]=d[now]+1;
	q.push(now-1);
	}

if(now+1<=200000&&d[now+1]==0){
d[now+1]=d[now]+1;
q.push(now+1);
}

if(now*2<=200000&&d[now*2]==0){
d[now*2]=d[now]+1;
q.push(now*2);
}
}

printf("%d",d[m]-1);
return 0;
}


