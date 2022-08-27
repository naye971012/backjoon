#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
int map[21][21]={0,};
int visited[21][21]={0,};
int n;

void reset(){
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			visited[i][j]=0;
		}
	}
}

bool empty_check(int max_size){
	int check=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j] < max_size && map[i][j]!=0) return false;
		}
	}
	return true;
	
}

int main(){
	scanf("%d",&n);	
	int check[10]={0,}; //물고기개수 
	int fir,sec;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			scanf("%d",&map[i][j]);
			check[map[i][j]]++;
			if(map[i][j]==9){
				fir=i; sec=j;
			} 
		}
	}
	
	int max_size=2; //물고기 최대크기 
	int num_fish=0;
	int i=1;
	while(1){
		num_fish+=check[i++];
		
		
		if(num_fish>=max_size){
			num_fish-=max_size;
			max_size++;
		}
		else break; //물고기 자라는 최대크기정하기 
	}
	
	int cur_size=2;
	int time=0;
	int eat_fish=0;
	int distance=100;
	int min_dis=100;
	
	int go_fir;
	int go_sec;
	
	queue<int> q;
	int dx[4]={-1,1,0,0};
	int dy[4]={0,0,-1,1};
	map[fir][sec]=0;
	while(!empty_check(max_size)){
		min_dis=100;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]<cur_size && map[i][j]!=0){
					
					
					reset();
					visited[i][j]=1;
					
					int a2=1;
					q.push(i*100+j);
					
					while(!q.empty()){
						int x=q.front();
						q.pop();
						
						for(int a=0;a<4;a++){
							int newx = x/100+dx[a];
							int newy = x%100+dy[a];
							if(visited[newx][newy]==0 && map[newx][newy] < cur_size && newx<n && newy<n && newx >=0 && newy >=0){
								q.push((newx)*100+newy);
								visited[newx][newy]=a2;
							}
						}
						a2++;	
					}
					distance=visited[fir][sec];
					
					for(int i2=0;i2<n;i2++){
						for(int j2=0;j2<n;j2++){
							printf("%d ",visited[i2][j2]);
						}
						printf("\n");
					}
					
					if (distance < min_dis){
						
						min_dis = distance;
						go_fir=i;
						go_sec=j;
					}
				}
			}
		} //자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없다. 
		map[fir][sec]=0;
		map[go_fir][go_sec]=0;
		fir=go_fir; sec=go_sec;
		
		eat_fish++;
		if(eat_fish == cur_size){
			cur_size++;
			eat_fish=0;
		}
		
		time+=min_dis;
		printf("%d %d          %d %d\n",fir,sec,eat_fish,time);
	}
	
	printf("%d",time);
	
	return 0;
}
