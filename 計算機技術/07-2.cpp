#include<stdio.h>
#include<stdlib.h>
int main(void){
	int a,b,n[10]{0},i,s;
	printf("�п�JA:B.....");
	scanf("%d:%d",&a,&b);
	printf("0~9���X�{���Ƭ�.....");
	for(;a<=b;a++){
		i=a;
		while(i!=0){
			s=i%10;
			n[s]++;
			i=i/10;
		}
	}
	for(i=0;i<10;i++){
		if(i==9) printf("%d",n[i]);
		else printf("%d, ",n[i]);
	}
	









}
