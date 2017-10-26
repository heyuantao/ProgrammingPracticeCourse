#include <stdio.h>
#include <stdlib.h>
#define NUM 50  /*���ֵ��Ϊ��Ϊ�����ṩһ������*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*����Ʒ����ѡ��i��ʾ��ǰ���ǵ�i����Ʒ��ѡ��ѡ��items��ʾ��Ʒ��������current��ʶ��ǰ������Ʒ�ļ�ֵ��
capacity��ʶ��ǰ���ڵĿռ仹�ж��٣�bestValue��ʾ���ű�����������Ʒ����*/
void backTrace(int i,int items,int weightArray[],int valueArray[],int currentValue,int capacity,int *bestValue){
	/* i �ķ�ΧΪ 0 - (items-1) */
	int valueWithoutIth;    /*��i����Ʒ��ѡʱ����������Ʒ�ļ�ֵ*/ 
	int valueWithIth;       /*��i����Ʒѡ��ʱ����������Ʒ�ļ�ֵ*/ 
	if(i==items){ /* ����(items-1)����Ʒ����i==itemsʱ����ʾ��Ʒ�Ѿ�ȫ��ѡ����ɣ���ʱ����Ҫ�����ֵ */
		if(currentValue>*(bestValue)){
			*bestValue=currentValue;
		}
		return; /*һ��Ҫ�з��أ�����������ѭ���Ӷ��ڴ����*/ 
	}
	valueWithoutIth=currentValue;
	valueWithIth=currentValue+valueArray[i];
	/*����i����Ʒ��ѡ��ʱ������������Ʒ�ĸ���ѡȡ�����ļ�ֵ*/ 
	backTrace(i+1,items,weightArray,valueArray,valueWithoutIth,capacity,bestValue);
	/*����i����Ʒѡ��ʱ������������Ʒ�ĸ���ѡȡ�����ļ�ֵ������ʱ����һ��Ҫ�ж���Ŀռ䣩*/ 
	if(capacity>0){
		backTrace(i+1,items,weightArray,valueArray,valueWithIth,capacity-weightArray[i],bestValue);
	}
	
}

int main(int argc, char *argv[]) {
	int weightArray[NUM];  //���ÿ����Ʒ���������� 
	int valueArray[NUM];   //���ÿ����Ʒ��ֵ������ 
	//int selectArray[NUM];  //��Ż����㷨ִ�й��̵ı���ѡ�� 
	int bestSelectArray[NUM]; //������ŵı���ѡ�� 
	int bestValue=0;           //�������������ֵ����ʼ��0 
	int i,j;         
	int items,capacity;  //items is the number of item,capacity is bag capacity
	/*������Ʒ�������ͱ���������������������� */
	scanf("%d %d",&items,&capacity);
	/*����ÿ����Ʒ������*/
	printf("Input The Wight List:");
	for(i=0;i<items;i++){
		scanf("%d",&weightArray[i]);
	}
	/*����ÿ����Ʒ�ļ�ֵ*/
	printf("Input The Value List:");
	for(i=0;i<items;i++){
		scanf("%d",&valueArray[i]);
	}
	backTrace(0,items,weightArray,valueArray,0,capacity,&bestValue);
	printf("The largest value for 0-1 backpack solution is:%d \n",bestValue);
	return 0;
}
