#include<stdlib.h>
#include<stdio.h>
int f(int x ,int y){
	while(x%y!=0&&y%x!=0){
		if(x>=y) x=x%y;
		else if(x<y) y=y%x;
	}
	if(x>y) return y;
	if(x<=y) return x;
}


int main(void){
	int x,y,n;
	printf("�п�J����Ϊ���(����)��...");
	scanf("%d",&x);
	printf("�п�J����Ϊ��e(����)��...");
	scanf("%d",&y);
	n=f(x,y);
	printf("�ֻ̤ݭn%d�ӬۦP������ΡA�Ʀ������%d�����������",(x*y)/(n*n),x*y/n);
}
