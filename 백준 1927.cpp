#include <iostream>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> pq;
	int m;
	int n;
	int save=0;
	scanf("%d",&m);
	int map[m*2]={0,};
	for(int i=0;i<m;i++){
		scanf("%d",&n);
		if (n == 0) {
			if (pq.empty() != 0) {
				map[save++]=0;
			}
			else {
				map[save++]=  pq.top() ;
				pq.pop();
			}

		}
		else {
			pq.push(n);
		}

	}
	for(int i=0;i<save;i++){
		printf("%d\n",map[i]);
	}
	return 0;
}
