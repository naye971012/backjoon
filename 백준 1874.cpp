#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#include<string.h>

#define MAX_STACK_SIZE 100000

typedef struct {
	int key;
} element;

element stack[MAX_STACK_SIZE]; //1. 스택 생성.

int top = -1;
int n;
int opt;
element pushnum;

void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1) {
		printf("full\n");
		return; //2. 스택full 판별
	}
	stack[++top] = item;
	return;
} //3. 스택에 push

element pop() {
	if (top == -1)
		printf("empty\n"); //4. 스택empty 판별
	return stack[top--];
} //5. 스택에서 pop


int main() {
	element data;
	
	scanf("%d", &n);
	int map[n];
	char save[n*2];
	int ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&map[i]);
	}
	int x=0;
	data.key=0;
	element check;
	while(1){
		
		
		if(map[x]==data.key){
			save[ans++]='-';
			
			pop();
			x++;
				
		}
		while(1){
		if(top!=-1){
			check=pop();
			if(check.key==map[x]){
				save[ans++]='-';
				x++;
			}
			else{
				push(check);
				break;
			}
		}
		else break;
		}
		
		if(x==n){
			
			for(int m=0;m<ans;m++){
				printf("%c\n",save[m]);
			}
			break;
			}
		if(data.key>n){
			printf("NO");
			break;
		}
		data.key++;
		push(data);
		save[ans++]='+';
		
		
	}
	
	
	return 0;
}

