#include <stdio.h>
#include <iostream>
using namespace std;
int map[129][129]={0,};
int white=0;
int blue=0;

int check(int beginx, int beginy,int size){
	int ans=0;
	for(int i=beginx;i<beginx+size;i++){
		for(int j=beginy;j<beginy+size;j++){
			ans+=map[i][j];
		}
	}
	//	cout << beginx << beginy << " ans=" << ans << "size= " << size << "\n" << endl;
	
	if(ans==0) {
	//	cout << "white\n" << endl;
		white++;
		return 0;}
	
	if( (size)*(size) == ans ){
//		cout << "blue\n" <<endl;
		blue++;
		return 0;
	}
	if(size>=2){
	check(beginx,beginy,size/2);
	check(beginx+size/2,beginy,size/2);
	check(beginx,beginy+size/2,size/2);
	check(beginx+size/2,beginy+size/2,size/2);
	}
	return 0;
}

int main(){
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> map[i][j];
		}
	}	
	
	check(1,1,n);
	
	cout << white << "\n" << blue << endl;  
	
	return 0;
}
