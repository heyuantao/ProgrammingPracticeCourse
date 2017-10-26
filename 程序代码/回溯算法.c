#include <stdio.h>
#include <stdlib.h>
#define NUM 50  /*这个值是为了为数组提供一个长度*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*对物品进行选择，i表示当前考虑第i建商品的选或不选，items表示物品的数量，current标识当前包内物品的价值，
capacity标识当前包内的空间还有多少，bestValue表示最优背包方案的商品重量*/
void backTrace(int i,int items,int weightArray[],int valueArray[],int currentValue,int capacity,int *bestValue){
	/* i 的范围为 0 - (items-1) */
	int valueWithoutIth;    /*第i建物品不选时，背包内物品的价值*/ 
	int valueWithIth;       /*第i建物品选择时，背包内物品的价值*/ 
	if(i==items){ /* 仅有(items-1)个物品，当i==items时，表示物品已经全部选择完成，这时仅需要计算价值 */
		if(currentValue>*(bestValue)){
			*bestValue=currentValue;
		}
		return; /*一定要有返回，否则程序会死循环从而内存溢出*/ 
	}
	valueWithoutIth=currentValue;
	valueWithIth=currentValue+valueArray[i];
	/*当第i建物品不选择时，计算余下物品的各种选取方案的价值*/ 
	backTrace(i+1,items,weightArray,valueArray,valueWithoutIth,capacity,bestValue);
	/*当第i建物品选择时，计算余下物品的各种选取方案的价值，（此时背包一定要有多余的空间）*/ 
	if(capacity>0){
		backTrace(i+1,items,weightArray,valueArray,valueWithIth,capacity-weightArray[i],bestValue);
	}
	
}

int main(int argc, char *argv[]) {
	int weightArray[NUM];  //存放每件物品重量的数组 
	int valueArray[NUM];   //存放每件物品价值的数组 
	//int selectArray[NUM];  //存放回溯算法执行过程的背包选择 
	int bestSelectArray[NUM]; //存放最优的背包选择 
	int bestValue=0;           //背包问题的最优值，初始化0 
	int i,j;         
	int items,capacity;  //items is the number of item,capacity is bag capacity
	/*输入物品的数量和背包的容量（体积或重量） */
	scanf("%d %d",&items,&capacity);
	/*输入每件物品的重量*/
	printf("Input The Wight List:");
	for(i=0;i<items;i++){
		scanf("%d",&weightArray[i]);
	}
	/*输入每件物品的价值*/
	printf("Input The Value List:");
	for(i=0;i<items;i++){
		scanf("%d",&valueArray[i]);
	}
	backTrace(0,items,weightArray,valueArray,0,capacity,&bestValue);
	printf("The largest value for 0-1 backpack solution is:%d \n",bestValue);
	return 0;
}
