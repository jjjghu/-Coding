#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(void){
	char input[17];
	int n,num[17],a,sum;
	while(1){
		printf("�п�J�d��:");
		scanf("%s",input);
		n=strlen(input);
		if(!(n==15||n==16)){
			printf("Error! �D15��16�d���Ʀr!");
			break;
		}
		for(a=0;a<n;a++){
			num[a]=(int)input[a]-48;
		}
		int check = 0;
		for(a=0;a<n;a++){
			if(num[a]<0||num[a]>9) check=1;
		}
		if(check==1){
			printf("Error! �D15��16�d���Ʀr!");
			break;
		}
		if(n==15){
			for(a=0,sum=0;a<n-1;a++){
				if(a%2!=0){
					num[a]=num[a]*2;
					num[a]=num[a]%10+num[a]/10;
				}
				sum=sum+num[a];
			}
			sum=sum%10;
			if(sum==0&&sum==num[14]){
				printf("�d�����T!!\n");
				continue;
			}
			else sum=10-sum;
			if(sum==num[14]) printf("�d�����T!!");
			else printf("�d�����~!!");
			
		}
		else if(n==16){
			for(a=0,sum=0;a<n-1;a++){
				if(a%2==0){
					num[a]=num[a]*2;
					num[a]=num[a]%10+num[a]/10;
				}
				sum=sum+num[a];
			}
			sum=sum%10;
			if(sum==0&&sum==num[15]){
				printf("�d�����T!!\n");
				continue;
			}
			else sum=10-sum;
			if(sum==num[15]) printf("�d�����T!!");
			else printf("�d�����~!!");
			
		}
		printf("\n");
		
	}

}
