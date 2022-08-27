#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main()
{	int x=0;
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
	
		priority_queue<int, vector<int> >max_pq; // ÃÖ´ë Èü
		priority_queue<int, vector<int>, greater<int> >min_pq; // ÃÖ¼Ò Èü
	
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			char cmd; cin >> cmd;
			if (cmd == 'I') {
				int n; cin >> n;
				max_pq.push(n);
				min_pq.push(n);
				x++;
			}
			else {
				int n; cin >> n;
				if (n == 1) {
			
					if (max_pq.empty()) continue;
					else {
						x--;
						max_pq.pop();
				
					}
				}
				else {
			
					if (min_pq.empty()) continue;
					else {
						x--;
						min_pq.pop();
			
					}
				}
			}
	
		} 
		if ( x<=0 ) cout << "EMPTY\n";
		else {
			cout << max_pq.top() << " " << min_pq.top() << "\n";
		}
		x=0;
	}
	return 0;
}
