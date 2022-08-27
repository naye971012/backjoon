#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �θ��带 ������
int getParent(int parent[], int node){
    if(parent[node] == node) {
        return node;
    }
    return getParent(parent, parent[node]);
}

// �� ����� �θ��带 ��ħ
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

// ���� �θ��带 ������ Ȯ��
int findParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x == y){
        // ���� �θ� ���
        return 1;
    }else{
        // �ٸ� �θ� ���
        return 0;
    }
}

// �������� ����
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

    // �Ÿ��� ������������ ����
    sort(v.begin(), v.end());    
    
    // �ʱ�ȭ
    int parent[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        if(!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)){
            // ����Ŭ�� ������ �ʴ� ��� (�ٸ� �θ� ���°��)
            sum += v[i].distance;
            // ������ �ϰ� ����, ���� �θ� ���� �ǹǷ�...
            unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
        }// end if
    }// end for
    
    // ��� Ȯ��
    cout << sum;
    
    return 0;
}
