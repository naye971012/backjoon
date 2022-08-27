#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 부모노드를 가져옴
int getParent(int parent[], int node){
    if(parent[node] == node) {
        return node;
    }
    return getParent(parent, parent[node]);
}

// 두 노드의 부모노드를 합침
int unionParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x < y){
        parent[y] = x;
        return x;
    }else {
        parent[x] = y;
        return y;
    }
}

// 같은 부모노드를 갖는지 확인
int findParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x == y){
        // 같은 부모 노드
        return 1;
    }else{
        // 다른 부모 노드
        return 0;
    }
}

// 간선들의 정보
class Edge{
    public:
    int node[2];
    int distance;
    Edge(int x, int y, int distance){
        this->node[0] = x;
        this->node[1] = y;
        this->distance = distance;
    }
    bool operator <(Edge &edge){
        return this->distance < edge.distance;
    }
};

int main(int argc, char* argv[]) {
    int n,m;
    cin >> n >>m;
    int fir,sec,cost;
    vector<Edge> v;
    for(int i=0;i<m;i++){
    	cin >> fir >> sec >> cost;
    	v.push_back(Edge(fir,sec,cost));
	}

    // 거리를 오름차순으로 정렬
    sort(v.begin(), v.end());    
    
    // 초기화
    int parent[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        if(!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)){
            // 사이클이 생기지 않는 경우 (다른 부모를 갖는경우)
            sum += v[i].distance;
            // 연결을 하고 나면, 같은 부모를 갖게 되므로...
            unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
        }// end if
    }// end for
    
    // 결과 확인
    cout << sum;
    
    return 0;
}
