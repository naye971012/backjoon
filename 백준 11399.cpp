#include <stdio.h>
#include <stdlib.h>
#include <string>
int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
    int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

    if (num1 < num2)    // a�� b���� ���� ����
        return -1;      // -1 ��ȯ
    
    if (num1 > num2)    // a�� b���� Ŭ ����
        return 1;       // 1 ��ȯ
    
    return 0;    // a�� b�� ���� ���� 0 ��ȯ
}


int main(){
	int n;
	scanf("%d",&n);
	int map[n];
	for(int i=0;i<n;i++){
		scanf("%d",&map[i]);
	}
	
	qsort(map,n,sizeof(int),compare);
	int m=n;
	int ans=0;
	for(int i=0;i<n;i++){
		map[i]*=m--;
		ans+=map[i];
	}
	printf("%d",ans);
	return 0;
}
