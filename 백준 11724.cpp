#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	vector<int> linked[n+1];
	int visited[n+1]={0,};
	queue<int> qu;
	int cur;
	int begin,end;
	
	for(int i=0;i<m;i++){
		cin >> begin >> end;
		linked[begin].push_back(end);
		linked[end].push_back(begin);
		
	}
	int ans=0;
	for(int x=1;x<=n;x++){
		if(visited[x]==0) {
			ans++;
			qu.push(x);
			
			while(!qu.empty()){
				cur=qu.front();
				visited[cur]=1;
				qu.pop();
				
				int csize= linked[cur].size();
				for(int i=0;i<csize;i++){
					if( visited[  linked[cur][i]  ]==0){
						visited[  linked[cur][i]  ]=1;
						qu.push( linked[cur][i] );
					}
				}
			
		}
	}	}
	cout << ans << endl;
	return 0;
}
