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
		map.push_back({sec,sec}); //������� 
	}
	sort(map.begin(),map.end()); // ���ļ� 
	sort(line.begin(),line.end()); //line[i].end�� �迭 
	
	vector<int> save[n];
	int dp[n];
	for(int i=0;i<n;i++){
		save[i].push_back(map[i].first);
	} 
	int x,y;
	for(int i=0;i<n;i++){
		x=map[i].first; //�������� 
		y=map[i].second;//������ġ
		dp[i]=
	}
	
	
	
	cout << "\n\n\n";
	for(int i=0;i<n;i++){
		cout<< line[i].first   <<" "<<line[i].second<<endl;
	}
	
	return 0;
}
