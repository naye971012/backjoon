#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int> > line;
	int fir,sec;
	vector<pair<int,int> > map;
	for(int i=0;i<n;i++){
		scanf("%d %d",&fir,&sec);
		line.push_back({fir,sec});
		map.push_back({sec,sec}); //순서기억 
	}
	sort(map.begin(),map.end()); // 정렬순 
	sort(line.begin(),line.end()); //line[i].end는 배열 
	
	vector<int> save[n];
	int dp[n];
	for(int i=0;i<n;i++){
		save[i].push_back(map[i].first);
	} 
	int x,y;
	for(int i=0;i<n;i++){
		x=map[i].first; //작은순서 
		y=map[i].second;//원래위치
		dp[i]=
	}
	
	
	
	cout << "\n\n\n";
	for(int i=0;i<n;i++){
		cout<< line[i].first   <<" "<<line[i].second<<endl;
	}
	
	return 0;
}
