#include <iostream>
#define MAX 10
 
using namespace std;
 
bool chess[MAX][MAX];
bool visited1[MAX * 2]; //�����ʿ��� �������� ���� �밢��
bool visited2[MAX * 2]; //���ʿ��� ���������� ���� �밢��
int bishop[2];
int chess_size;
 
//for������ ����Լ������� �����ϱ�
// color == 0 : ������, color == 1 : ���
void DFS(int cnt, int x, int y, int color) {
    if (x >= chess_size) {
        y++;
        if (x % 2 == 0) x = 1;
        else x = 0;
    }
    if (y >= chess_size) {
        if (cnt > bishop[color])
            bishop[color] = cnt;
        return;
    }
 
    if (chess[y][x] && !visited1[x + y + 1] && !visited2[x - y + chess_size]) {
        visited1[x + y + 1] = true;
        visited2[x - y + chess_size] = true;
        DFS(cnt + 1, x + 2, y, color);
        visited1[x + y + 1] = false;
        visited2[x - y + chess_size] = false;
    }
    DFS(cnt, x + 2, y, color);
}
 
int main(void) {
    cin >> chess_size;
 
    for (int i = 0; i < chess_size; i++)
        for (int j = 0; j < chess_size; j++)
            cin >> chess[i][j];
    
    DFS(0, 0, 0, 0); //������ ü����
    DFS(0, 1, 0, 1); //��� ü����
 
    cout << bishop[0] + bishop[1] << '\n';
}

