#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define NUM 50
#define CAP 1500

int max(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int main(int argc, char *argv[]) {
	int Weight[NUM];
	int Value[NUM];
	int Select[NUM];  //store the select status for every items 
	int P[NUM][CAP];  //store the value of every step
	int i,j;         
	int items,capacity;  //items is the number of item,capacity is bag capacity
	/*items is the number of bones,capacity is the capacity for bag */
	scanf("%d %d",&items,&capacity);
	/*Fill the Weight Array*/
	printf("Input The Wight List:");
	for(i=0;i<items;i++){
		scanf("%d",&Weight[i]);
	}
	/*Fill the Value Array*/
	printf("Input The Value List:");
	for(i=0;i<items;i++){
		scanf("%d",&Value[i]);
	}
	/*the init part of equation*/ 
	for(j=capacity;j>=0;j--){
		if(j>Weight[items-1]){   /*(items-1) is the last item*/
			P[items-1][j]=Value[items-1];
		}else{
			P[items-1][j]=0;
		}
		
	}
	/*the main part of equation*/
	for(i=items-2;i>=0;i--){
		for(j=capacity;j>=0;j--){		
			if((0<=j)&&(j<Weight[i])){
				P[i][j]=P[i+1][j]; 				
			}else{
				P[i][j]=max(P[i+1][j],P[i+1][j-Weight[i]]+Value[i]);
			} 
		}
	}
	printf("The max value is:%d \n",P[0][capacity]);
	
	/*Display the select of the item*/
	for(i=0;i<=items-1;i++){
		if(P[i][capacity]==P[i+1][capacity]){
			Select[i]=0;
		}else{
			Select[i]=1;
			capacity=capacity-Weight[i];			
		}
	}
	
	/*display the selection*/
	printf("This is the item selection !\n");
	for(i=0;i<=items-1;i++){
		printf("%d ",Select[i]);
	}
	printf("\n");
	return 0;
}
