#include<stdio.h>
void name(int n){
	printf("Name of the student : ");
	switch(n){
		case 1:
			printf("A");
			break;
		case 2:
			printf("B");
			break;
		case 3:
			printf("C");
			break;
		case 4:
			printf("D");
			break;
		case 5:
			printf("E");
			break;
		default:
			printf("INVALID ROLL NO.");	
	}
}
	int attend[5][30];
int main(){
	int roll[5] = {1,2,3,4,5};
	int n,c,mark,sum = 0,i,j;
	int day;
	while(c != 0){
		printf("\n1.Track attendence\n2.Make attendence\n3.End Task\n");
		scanf("%d", &c);
		switch(c){
			case 1:
				printf("Enter your Roll number : ");
				scanf("%d", &n);
				for(i = 0;i < 30; i++){
					sum += attend[n][i];	
				}
				printf("NO. of days present : %d",sum);
				break;
			case 2:
			
				printf("Day : ");
				scanf("%d", &day);
				printf("Enter your Roll number : ");
				scanf("%d", &n);
				name(n);
				printf("\n1.Present\n2.Absent\n");
				scanf("%d", &mark);
//				for(j = 0;j < 30;j++){
				if(mark == 1 && day <= 30) attend[n][day-1] = 1;
//				}
				break;
			default :
				c = 0;
		}	
	}
	return 0;
}